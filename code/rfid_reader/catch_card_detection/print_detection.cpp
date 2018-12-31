#include <wiringPi.h>
#include <iostream>

//Operational.
//This program prints a message in the terminal when the rfid reader detects a card. It stops after 5 activations.
int	main(void)
{
	wiringPiSetup();
	pinMode(0, INPUT);
	pullUpDnControl(0, PUD_DOWN);
	int i = 0;

	while (i != 5)
	{
		while (digitalRead(0) == LOW)
			delay(500);
		std::cout << "pin = 1" << std::endl;
		while (digitalRead(0) == HIGH)
			delay(500);
		std::cout << "pin = 0" << std::endl;
		delay(500);
		i++;
	}
	return (0);
}
