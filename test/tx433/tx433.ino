// мелкий передатчик 3.6V SYN115
#define G433_BUFSIZE 50   // размер буфера
#define G433_SPEED 2000   // скорость бит/сек (минимальная)
#include <Gyver433.h>
Gyver433_TX tx(0);  // указали пин
int ledPin = 1;
int analogInPin2 = 2;
void setup() {
    pinMode(ledPin, OUTPUT);
}

char data[] = "Hello from #xx";
byte count = 0;

void loop() {

   if(analogRead(analogInPin2)>150)
 {
  digitalWrite(ledPin, HIGH);
  data[12] = (count / 10) + '0';
  data[13] = (count % 10) + '0';
  if (++count >= 100) count = 0;
  tx.sendData(data);  
  delay(500);
 }
 else 
   {                     
    digitalWrite(ledPin, LOW);    
  } 
}
