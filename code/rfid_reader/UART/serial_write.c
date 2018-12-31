#include <wiringPi.h>
#include <wiringSerial.h>

int	main(void)
{
	int fd;
	int i = 0;

	if (wiringPiSetup() < 0) return 1;
	if ((fd = serialOpen("/dev/ttyAMA0", 9600)) < 0) return (1);
	while(i++ != 5)
		serialPuts(fd, "Salut les amis !\n");
	serialClose(fd);
	return (0);
}
