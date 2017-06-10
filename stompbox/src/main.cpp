#include <Arduino.h>
#include <Bounce.h>

const int channel = 2;
const int ledPin = 13;
int d1;
int d2;
int inputChannel;
Bounce button1 = Bounce(11, 5);
Bounce button2 = Bounce(12, 5);
Bounce button3 = Bounce(10, 5);

void Sync() {
  // do something for every MIDI Clock pulse when the sequencer is running
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

byte counter;
byte CLOCK = 248;
byte START = 250;
byte CONTINUE = 251;
byte STOP = 252;

void RealTimeSystem(byte realtimebyte) {
  if (realtimebyte == 248) { // clock signal
    counter++;
    // boolean advance = (counter % 6) == 0;
    if (counter % 12 == 0) { // eighth that isn't on a quarter, led off
      digitalWrite(ledPin, LOW);
    }
    if (counter % 24 == 0) { // quarter note, turn the led on
      counter = 0;
      digitalWrite(ledPin, HIGH);
    }
  }
}

void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Sync();
  usbMIDI.setHandleRealTimeSystem(RealTimeSystem);
}

void loop() {
  usbMIDI.read(1);
  button1.update();
  button2.update();
  button3.update();
  if (button1.fallingEdge()) usbMIDI.sendNoteOn(60, 99, channel);
  if (button1.risingEdge()) usbMIDI.sendNoteOff(60, 0, channel);
  if (button2.fallingEdge()) usbMIDI.sendNoteOn(58, 99, channel);
  if (button2.risingEdge()) usbMIDI.sendNoteOff(58, 0, channel);
  if (button3.fallingEdge()) usbMIDI.sendNoteOn(57, 99, channel);
  if (button3.risingEdge()) usbMIDI.sendNoteOff(57, 0, channel);
}
