#include <Arduino.h>
#include <VirtualWire.h>
#include "pitches.h"

int ledPin = 1;
int analogInPin2 = 1; // analogRead(1) takes place at P2
const int BUZZER = 5;
int VAL = 1;

int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  vw_set_tx_pin(0);
  vw_setup(2000); // Bits per sec
}
void loop() {
  if(analogRead(analogInPin2)>150){
    digitalWrite(ledPin, HIGH);
    vw_send((byte *)VAL, 1);
    vw_wait_tx(); // Wait until the whole message is gone
delay(200);
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//     int noteDuration = 1000 / noteDurations[thisNote];
//     tone(BUZZER, melody[thisNote], noteDuration);
//     int pauseBetweenNotes = noteDuration * 1.30;
//     delay(pauseBetweenNotes);
//     noTone(BUZZER);
//  }
     
  }
  else{                     
    digitalWrite(ledPin, LOW);    
  }                     
}
