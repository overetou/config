#!/usr/bin/env python

import time
import serial

ser = serial.Serial(
	port='/dev/ttyAMA0',
	baudrate=115200,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=1
)

packet = bytearray()
packet.append(0xBA)
packet.append(0x2)
packet.append(0x1)
packet.append(0xB9)

ser.write(packet)

print hex(ord(ser.read()))
print hex(ord(ser.read()))
print hex(ord(ser.read()))
print hex(ord(ser.read()))
