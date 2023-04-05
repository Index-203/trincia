#include <Arduino.h>
#include <Servo.h>
#include <RF24.h>
#include <Arduino_FreeRTOS.h>

#define ptaglio 40
#define psblocco 42

//definizione servo
Servo acceleratore;
Servo freno;
Servo cambio_sel;
Servo cambio_inn;
Servo sblocc_dx;
Servo sblocc_sx;
Servo trincia_inn;
Servo freno_trincia;

void setup() {
  //servo inizializzazione
  acceleratore.attach(22); 
  freno.attach(24);
  cambio_sel.attach(28);
  cambio_inn.attach(30);
  sblocc_dx.attach(32);
  sblocc_sx.attach(34);
  trincia_inn.attach(36);
  freno_trincia.attach(38); 

  //inizializzazione pistoni elettrici
  pinMode(ptaglio, OUTPUT);
  pinMode(psblocco, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}