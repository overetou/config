#include "EMSGyro.hpp"

int	main(void)
{
	EMSGyro	simpleGyro;

	std::cout << "Gyro succesfuly initialised." << std::endl;
//	simpleGyro.setScriptName("src/script.py");
	simpleGyro.open(NULL);
	std::cout << "Gyro script launched." << std::endl;
	simpleGyro.iocontrol(NULL);

	int i = 0;
	char c;
	simpleGyro.read(&c);//dismisses the newline of iocontrol.
	while (i != 5)
	{
		if (simpleGyro.read(&c))
		{
			if (c == 'U')
				std::cout << "Moving Up." << std::endl;
			else if (c == 'D')
				std::cout << "Moving Down." << std::endl;
			else
				std::cout << "An error occured. Read char = " << c << std::endl;
			i++;
			simpleGyro.read(&c);//dismisses the newline.
		}
	}
	std::cout << "End of the program. You should now have calibrated the sensor." << std::endl;
	return (0);
}
