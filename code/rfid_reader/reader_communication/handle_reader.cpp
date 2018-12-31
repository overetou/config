#include <wiringPi.h>//rasp pi pin manipulation
#include <wiringSerial.h>//serial communication
#include <stdlib.h>//exit
#include <iostream>//streams
#include <unistd.h>

#define TALK_PREAMBLE 0xBA
#define LISTEN_PREAMBLE 0xBD
#define SELECT 0X01

static int	ft_putnbr_hex(unsigned int n, int i)
{
	char	base[] = "0123456789ABCDEF";
	
	if (n / 16 != 0)
		i = ft_putnbr_hex(n / 16, i);
	write(1, &(base[n % 16]), 1);
	return (i + 1);
}

void	msg_exit(const char* str) {
	std::cout << str << std::endl;
//	serialClose(fd);
	exit(EXIT_FAILURE);
}

int 	inputUpdate(const int fd, int* checksum) {
	int	input;
	input = serialGetchar(fd);
	if (input == -1)
		msg_exit("No input found on serial port.");
	ft_putnbr_hex(input, 0);
	*checksum = *checksum ^ input;
	return input;
}

void	checkInput(const int fd, int* checksum, int toMatch, const char* errorMsg) {
	if (inputUpdate(fd, checksum) != toMatch)
		msg_exit(errorMsg);
}

int	processSelectStatus(const int fd, int* checksum) {
	int input;
	input = inputUpdate(fd, checksum);
	if (input == 0 || input == 1)
		return input;
	if (input == 0XF0)
		msg_exit("Checksum error returned.");
	msg_exit("Unexpected select status returned.");
	return -1;//THis point is not supposed to be reached.
}

bool	select(const int fd) {
	int	checksum = 0;
	int	status;

	serialPutchar(fd, TALK_PREAMBLE);//sends preamble
	serialPutchar(fd, 2);//sends request length
	serialPutchar(fd, SELECT);//sends command
	serialPutchar(fd, (TALK_PREAMBLE ^ 2 ^ SELECT));//sends request's checksum.
	checkInput(fd, &checksum, LISTEN_PREAMBLE, "Unexpected response preamble.");//Checks returned preamble.
	checkInput(fd, &checksum, 5, "Unexpected returned length.");//get returned length
	checkInput(fd, &checksum, SELECT, "Unexpected command index returned.");//check returned command index
	status = processSelectStatus(fd, &checksum);//process returned status
	inputUpdate(fd, &checksum);//get UID (currently, we are not using the result)
	inputUpdate(fd, &checksum);//get type (currently, we are not using the result)
	if (serialGetchar(fd) != checksum)//check checksum
		msg_exit("Checksum matching failed.");
	return status;
}

int	main(void) {
	int fd;

	if (wiringPiSetup() < 0) {
		std::cout << "WringPi setup failed." << std::endl;
		return 1;
	}
	if ((fd = serialOpen("/dev/ttyAMA0", 115200)) < 0) {
		std::cout << "The opening of the serial ports failed." << std::endl;
		return 1;
	}
	pinMode(0, INPUT);//Sets the pin 0 as an input.
	pullUpDnControl(0, PUD_DOWN);//Sets it to go high when signal is high and low when signal is low.
	while (digitalRead(0) == LOW)//loop while no card in detection range.
		delay(500);
	std::cout << "Card detected." << std::endl;
	std::cout << "Select = " << select(fd) << std::endl;
	serialClose(fd);
	return 0;
}
