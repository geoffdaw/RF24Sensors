#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7, 8);

byte pipeName[] = {"pipe1"};
char message[40];

void setup() {
  // start serial port 
  Serial.begin(9600); 
  // start radio
  radio.begin();
  radio.openReadingPipe(1, pipeName);
  radio.startListening();
}

void loop() {
  // Have we got an incoming message?
  if (radio.available()) {
    while (radio.available()) {
      radio.read(&message, 11);
      message[11] = 0;
      Serial.write(message);
    }
  }
  // Have we got an outbound message?
  while (Serial.available() >= 11) {
    // Avoid corrupt or partial messages
    // All valid messages start with 'a' and are 11 chars
    char c = Serial.peek();
    if (c == 'a') {
      // We have at least 11 chars starting with 'a' 
      byte bytes = Serial.readBytes(message, 11);
      if (bytes == 11) {
        radio.stopListening();
        radio.write(&message, 11);
        radio.startListening();
      }
    }
    else {
      // Not an 'a' so ignore
      Serial.read();
    }
  }
  delay(2000);

}
