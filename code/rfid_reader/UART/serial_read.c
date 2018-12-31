#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(0, &c, 1);
}

int	main(void)
{
	int fd;

	if (wiringPiSetup() < 0) return 1;
	if ((fd = serialOpen("/dev/ttyAMA0", 9600)) < 0) return (1);
	while (1)
	{
		ft_putchar((char)serialGetchar(fd));
	}
	serialClose(fd);
	return (0);
}
