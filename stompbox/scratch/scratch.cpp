// byte midi_start = 0xfa;
// byte midi_stop = 0xfc;
// byte midi_clock = 0xf8;
// byte midi_continue = 0xfb;
// int play_flag = 0;
// byte data;
//
// void setup() {
//   Serial.begin(31250);
// }
//
// void loop() {
//   if (Serial.available() > 0) {
//     data = Serial.read();
//
//     if (data == midi_start) {
//       play_flag = 1;
//     } else if (data == midi_continue) {
//       play_flag = 1;
//     } else if(data == midi_stop) {
//       play_flag = 0;
//     } else if((data == midi_clock) && (play_flag == 1)) {
//       Sync();
//     }
//   }
// }
//
// void Sync() {
// // do something for every MIDI Clock pulse when the sequencer is running
// }



// #include <Arduino.h>
// #include <Bounce.h>
//
// const int channel = 1;
// const int ledPin = 14;
// int d1;
// int d2;
// int inputChannel;
// Bounce button1 = Bounce(11, 5);
// Bounce button2 = Bounce(12, 5);
// Bounce button3 = Bounce(10, 5);
//
// void setup() {
//   pinMode(10, INPUT_PULLUP);
//   pinMode(11, INPUT_PULLUP);
//   pinMode(12, INPUT_PULLUP);
//   pinMode(ledPin, OUTPUT);
//   digitalWrite(ledPin, HIGH);
//   delay(1000);
//   digitalWrite(ledPin, LOW);
//   delay(1000);
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
//   // MIDI Controllers should discard incoming MIDI messages.
//   if (usbMIDI.read()) {
//     d1 = usbMIDI.getData1();
//     d2 = usbMIDI.getData2();
//     inputChannel = usbMIDI.getChannel();
//   }
// }
