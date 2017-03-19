# RF24Sensors
A collection of Arduino based sensors using the nRF24L01 radio module. The collection includes an Arduino based Interface device that receives and transmits messages from/to the sensors and is connected to a Raspberry Pi or any other controller via a USB.

The sensors implement a subset of the 11 character LLAP messages as originally used by Ciseco/ Wireless Things devices. All messages are 11 characters and begin with a lowercase 'a' followed by a 2 character device id. The remainder of the message is device specific e.g. aABTEMP21.4.

Only a subset of the full list of LLAP messages is required as many of them were only used for device configuration. These sensors are configured by tailoring the Arduino sketch that is loaded to the device. For example a temperature device only requires two messages:
- aXXTEMPnn.n or aXXTEMP-n.n
- aXXBATTn.nn


