#include <Arduino.h>
#include <Servo.h>
#include <RF24.h>
#include <Arduino_FreeRTOS.h>

#define pCut 40
#define pUnlock 42

//servos
Servo throttle;
Servo brakes;
Servo shifter_sel;
Servo shifter_eng;
Servo unlock_right;
Servo unlock_left;
Servo trincia_eng;
Servo trincia_brakes;

void setup() {

    //servo initialization
    throttle.attach(22);
    brakes.attach(24);
    shifter_sel.attach(28);
    shifter_eng.attach(30);
    unlock_right.attach(32);
    unlock_left.attach(34);
    trincia_eng.attach(36);
    trincia_brakes.attach(38);

    //electric pistons initialization
    pinMode(pCut, OUTPUT);
    pinMode(pUnlock, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(1000);                      // wait for a second
}