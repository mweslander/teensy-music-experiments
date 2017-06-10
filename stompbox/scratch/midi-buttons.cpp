// #include <Arduino.h>
// #include <Bounce.h>
//
// const int channel = 2;
// const int ledPin = 14;
// int d1;
// int d2;
// int inputChannel;
// Bounce button1 = Bounce(11, 5);
// Bounce button2 = Bounce(12, 5);
// Bounce button3 = Bounce(10, 5);
//
// void Sync() {
//   // do something for every MIDI Clock pulse when the sequencer is running
//   digitalWrite(ledPin, HIGH);
//   delay(100);
//   digitalWrite(ledPin, LOW);
//   delay(100);
// }
//
// void setup() {
//   pinMode(10, INPUT_PULLUP);
//   pinMode(11, INPUT_PULLUP);
//   pinMode(12, INPUT_PULLUP);
//   pinMode(ledPin, OUTPUT);
//   Sync();
// }
//
// void loop() {
//   button1.update();
//   button2.update();
//   button3.update();
//   if (button1.fallingEdge()) usbMIDI.sendNoteOn(60, 99, channel);
//   if (button1.risingEdge()) usbMIDI.sendNoteOff(60, 0, channel);
//   if (button2.fallingEdge()) usbMIDI.sendNoteOn(58, 99, channel);
//   if (button2.risingEdge()) usbMIDI.sendNoteOff(58, 0, channel);
//   if (button3.fallingEdge()) usbMIDI.sendNoteOn(57, 99, channel);
//   if (button3.risingEdge()) usbMIDI.sendNoteOff(57, 0, channel);
//
//   if (usbMIDI.read()) {
//     d1 = usbMIDI.getData1();
//     d2 = usbMIDI.getData2();
//     inputChannel = usbMIDI.getChannel();
//     usbMIDI.sendSysEx(length, array)
//   }
// }
