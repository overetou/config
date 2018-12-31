#include <wiringPi.h>
#include <wiringSerial.h>
#include <iostream>

//Operationnal. The version 1.1 correctly wired with an additionnal 10k ohm resistance on the tagsta output will only activate the stream when a card is within detection range.
int	main(void)
{
	int fd;
	char output = '1';

	if (wiringPiSetup() < 0) return 1;
	if ((fd = serialOpen("/dev/ttyAMA0", 115200)) < 0) return (1);
	pinMode(0, INPUT);
	pullUpDnControl(0, PUD_DOWN);
	while (1)
	{
		if (digitalRead(0) == HIGH)
			std::cout << output;
	}
	serialClose(fd);
	return (0);
}
