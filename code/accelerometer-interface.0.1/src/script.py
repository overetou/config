import logging
import sys
import time

from Adafruit_BNO055 import BNO055

# Create and configure the BNO sensor connection.  Make sure only ONE of the
# below 'bno = ...' lines is uncommented:
# Raspberry Pi configuration with serial UART and RST connected to GPIO 18:
bno = BNO055.BNO055(serial_port='/dev/serial0', rst=18)

# Enable verbose debug logging if -v is passed as a parameter.
if len(sys.argv) == 2 and sys.argv[1].lower() == '-v':
    logging.basicConfig(level=logging.DEBUG)

# Initialize the BNO055 and stop if something went wrong.
if not bno.begin():
    raise RuntimeError('Failed to initialize BNO055! Is the sensor connected?')

# Print system status and self test result.
status, self_test, error = bno.get_system_status()
print('System status: {0}'.format(status))
print('Self test result (0x0F is normal): 0x{0:02X}'.format(self_test))
# Print out an error if system status is in error mode.
if status == 0x01:
    print('System error: {0}'.format(error))
    print('See datasheet section 4.3.59 for the meaning.')

# Print BNO055 software revision and other diagnostic data.
sw, bl, accel, mag, gyro = bno.get_revision()
print('Software version:   {0}'.format(sw))
print('Bootloader version: {0}'.format(bl))
print('Accelerometer ID:   0x{0:02X}'.format(accel))
print('Magnetometer ID:    0x{0:02X}'.format(mag))
print('Gyroscope ID:       0x{0:02X}\n'.format(gyro))

while sys != 3 or gyro != 3 or accel != 3 or mag != 3:
    # Read the calibration status, 0=uncalibrated and 3=fully calibrated.
    sys, gyro, accel, mag = bno.get_calibration_status()
    print(sys, gyro, accel, mag)
    # Sleep for a second until the next reading.
    time.sleep(1)
print('Calibration ok !')
print ('Z')

#time.sleep(30)
#i will increment until 4 before signaling anything, to prevent false positive from vibrations (moving up and down prevents the led from flashing). To increment i, a significant absolute z axis value (> 0.55m/(s*s)) must be observed, and have the same sign as the last. Else reset. 'U' for 'up', 'D' for 'down'.
i = 0
#last represents the sign of the last significative acceleration. True = + False = -
last = False
while True:
	x, y, z = bno.read_linear_acceleration()
	if z > 0.55:
		if last:
			i = i + 1
			if i == 4:
				print ('U')
				i = 0
		else:
			i = 0
			last = True
	elif z < -0.55:
		if last == False:
			i = i + 1
			if i == 4:
				print ('D')
				i = 0
		else:
			i = 0
			last = False
	else:
		i = 0
	time.sleep(0.1)
