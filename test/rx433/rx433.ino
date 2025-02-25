// крупный приёмник 5.0 SYN480R

#define G433_BUFSIZE 50   // размер буфера
#define G433_SPEED 2000   // скорость бит/сек (минимальная)

#include <Gyver433.h>
#include "pitches.h"
Gyver433_RX rx(0);
int ledPin = 1;
const int BUZZER = 4;

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
}

void loop() {
  // tick принимает асинхронно, но может ловить ошибки при загруженном коде
  // tickWait блокирует выполнение, но принимает данные чётко
  if (rx.tick()) {
    digitalWrite(ledPin, HIGH);
    byte buf[64];
    rx.readData(buf);
 
    tone(BUZZER, 800, 100);
    digitalWrite(ledPin, LOW);
   }

}
