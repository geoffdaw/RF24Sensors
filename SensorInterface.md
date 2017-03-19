## Description
The SensorInterface sketch provides the link between controlling software and the network of sensors. It connects to the computer running the controlling software by USB and appears as a serial device running at 9600 baud. In the case of a Raspberry Pi, the interface device usually appears as /dev/ttyACM0. All messages are 11 character in the LLAP format used by Ciseco/Wireless Things so controlling software previously developed for the Slice of Pi may only require changing to use a different serial device.

## Hardware
The SensorInterface requires an Arduino with a USB connector, such as the Uno or Nano, and an nRF24L01. The radio is connected as described in the ReadMe.

## Required libraries
RF24 by TMRh20 Version 1.2.0
