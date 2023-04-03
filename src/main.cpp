#include <Arduino.h>
#include <Servo.h>
#include <RF24.h>

#define ptaglio 13
#define psblocco 14

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
  acceleratore.attach(9); 
  freno.attach(9);
  cambio_sel.attach(9);
  cambio_inn.attach(9);
  sblocc_dx.attach(9);
  sblocc_sx.attach(9);
  trincia_inn.attach(9);
  freno_trincia.attach(9); 

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