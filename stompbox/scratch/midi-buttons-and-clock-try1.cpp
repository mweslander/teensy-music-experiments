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
// byte sequence[16][128]; // store the sequence for each midi note
// int pos = 0; // current sequence position
//
// int note = 36; // the current note being edited
// int accentMult = 1.4;
// int vel_cc = 7; // the CC used to set base velocity
//
// // this stores the base velocity for each MIDI note
// byte velocities[128];
//
// // advance the sequence and play all notes for the current sequence
// // send a note off before a note on so that we don't overlap notes
// void SendNextInSequence() {
//   for (int idx = 0; idx < 128; idx++) {
//     usbMIDI.sendNoteOff(idx, 0, channel);
//     if (sequence[pos][idx] > 0) {
//       byte vel = velocities[idx];
//       if (sequence[pos][idx] >= 2) {
//         int tmp = vel * accentMult;
//         if (tmp > 127) tmp = 127;
//         vel = (byte)tmp;
//       }
//       usbMIDI.sendNoteOn(idx, vel, channel);
//     }
//   }
//   pos = (pos + 1) % 16;
// }
//
// // send a note off for all notes
// void ClearNote() {
//   for (int idx = 0; idx < 128; idx++) {
//     usbMIDI.sendNoteOff(idx, 0, channel);
//   }
// }
//
// // reset to the beginning of the sequence
// void ResetSequence() {
//   pos = 0;
// }
//
// byte counter;
// byte CLOCK = 248;
// byte START = 250;
// byte CONTINUE = 251;
// byte STOP = 252;
//
// void RealTimeSystem(byte realtimebyte) {
//   if (realtimebyte == 248) { // clock signal
//     counter++;
//     boolean advance = (counter % 6) == 0;
//     if (counter % 12 == 0) { // eighth that isn't on a quarter, led off
//       digitalWrite(13, LOW);
//     }
//     if (counter % 24 == 0) { // quarter note, turn the led on
//       counter = 0;
//       digitalWrite(13, HIGH);
//     }
//     if (advance) { // sixteenth note, next in sequence
//       SendNextInSequence();
//     }
//   }
//   if (realtimebyte == START || realtimebyte == CONTINUE) {
//     counter = 0;
//     if (realtimebyte == START) ResetSequence();
//     digitalWrite(13, HIGH); // make sure it blinks the first time
//     SendNextInSequence(); // make sure we send the next item
//   } else if (realtimebyte == STOP) {
//     digitalWrite(13, LOW);
//     ClearNote();
//   }
// }
//
// void setup() {
//   pinMode(10, INPUT_PULLUP);
//   pinMode(11, INPUT_PULLUP);
//   pinMode(12, INPUT_PULLUP);
//   pinMode(ledPin, OUTPUT);
//   usbMIDI.setHandleRealTimeSystem(RealTimeSystem);
//   digitalWrite(13, HIGH);
//   delay(1000);
//   digitalWrite(13, LOW);
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
//
//   usbMIDI.read();
// }
