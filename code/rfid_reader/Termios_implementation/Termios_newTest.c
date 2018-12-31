#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MYRATE B115200

void	errExit(const char* msg)
{
	printf("%s\n", msg);
	exit(0);
}

//If the test is false, exits after displaying a message chosen at function call.
void	sec(int test, const char* msg)
{
	if (test == -1)
		errExit(msg);
}

static int	ft_putchr_hex(char n, int i)
{
	char	base[] = "0123456789ABCDEF";
	
	if (n / 16 != 0)
		i = ft_putchr_hex(n / 16, i);
	write(1, &(base[n % 16]), 1);
	return (i + 1);
}

//Display a string of 7 caracters in hexadecimal. Useful to quicly compare received data to the documentation.
void	disp_hex(char* buffer)
{
	int i = 0;

	while (i != 7)
	{
		ft_putchr_hex(buffer[i], 0);
		write(1, " ", 1);
		i++;
	}
}

//Writes the bytes. May read it, the commented part does not work however. If you did not know, C accepts absolute values under different format, hexadecimal included.
void	try_communication(int fd)
{
	char	writebuff[4];
	char	readbuff[7];

	writebuff[0] = 0xBA;
	writebuff[1] = 0x02;
	writebuff[2] = 0x01;
	writebuff[3] = 0xB9;

	readbuff[0] = 0;
	readbuff[1] = 0;
	readbuff[2] = 0;
	readbuff[3] = 0;
	readbuff[4] = 0;
	readbuff[5] = 0;
	readbuff[6] = 0;
	write(fd, writebuff, 4);
//	read(fd, readbuff, 4);
//	disp_hex(readbuff);
}

//This should work. Line 95 does the job in one line however. You choose...
//void	change_speed(struct termios *config, int fd)
//{
//	sec(cfsetospeed(config, MYRATE), "Set speed.");
//	sec(cfsetispeed(config, MYRATE), "Set speed.");
//}

//We use termios function to setup serial settings, especially cfmakeraw(). I left manual configuration of the structure commented. It didn't work but may save some time if you just have to modify some parts to test something. After that try communication will try to send a command to the reader, hoping for a response.
int	main(void)
{
	struct	termios	config;
	const char *device = "/dev/ttyAMA0";
	int	fd;

	fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
	sec(fd, "open failed.");
	tcgetattr(fd, &config);
	cfmakeraw(&config);
//	config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);
//	config.c_oflag = 0;
//	config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
//	config.c_cflag &= ~(CSIZE | PARENB);
//	config.c_cflag |= CS8;
//	config.c_cc[VMIN] = 1;
//	config.c_cc[VTIME] = 0;
	if (cfsetispeed(&config, MYRATE) < 0 || cfsetospeed(&config, MYRATE) < 0) printf("Speed set failed\n");
	tcsetattr(fd, TCSAFLUSH, &config);
	try_communication(fd);
	close(fd);
	return (0);
}
