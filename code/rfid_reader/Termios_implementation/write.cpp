#include <termios.h>
#include <unistd.h>

void	msg_exit(const char* str) {
	std::cout << str << std::endl;
	exit(EXIT_FAILURE);
}

void	msg_close_exit(const char* str, const int fd) {
	serialClose(fd);
	msg_exit(str);
}

int	open_reader(void)
{
	int	fd;
	struct termios termios_p;
	
	fd = open("/dev/ttyAMA0", O_RDWR);
	if (fd == -1)
		msg_exit("Error when opening the port.");
	tcgetattr(fd, &termios_p);
	termios_p.c_iflag = IGNBRK;
	termios_p.c_oflag = 0;
	termios_p.c_cflag = B115200 | CS8;
	termios_p.c_lflag = ECHO;
	termios_p.c_cc[VMIN] = 1;
	termios_p.c_cc[VTIME] = 0;
	tcsetattr(fd, TCSANOW, &termios_p);
	return (fd);
}

void	SerPutB(char c)
{
	write(fd, &c, 1);
}

int	main(void)
{
	int	fd;

	fd = open_reader();
	SerPutB(0xBA);
	SerPutB(0x2);
	SerPutB(0x1);
	SerPutB(0xB9);
	return (0);
}
