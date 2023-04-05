#include <Arduino.h>
#include <Servo.h>
#include <RF24.h>
#include <Arduino_FreeRTOS.h>

#define pCut 40 //piston height cut
#define pCut1 41 //piston height cut
#define pUnlock 42 //piston lock
#define pUnlock1 43 //piston lock
#define safe_stop 43 //safety stop

//servos
Servo throttle;
Servo brakes;
Servo shifter_sel;
Servo shifter_eng;
Servo unlock_right;
Servo unlock_left;
Servo rotor_mower_eng;
Servo rotor_brakes;

void setup() {

    //servo initialization
    throttle.attach(22);//var 0 180                 //potentiometer
    brakes.attach(24);//0 180                       //by software
    shifter_sel.attach(28);//var 0 180  r 0 1 2 3   //recive r 0 1 2 3
    shifter_eng.attach(30);//0 180                  //by software & recive
    unlock_right.attach(32);//var 0 180 3 pos       //recive 3 valor pos 1 pos 2 pos 3
    unlock_left.attach(34);//var 0 180  3 pos       //recive 3 valor pos 1 pos 2 pos 3
    rotor_mower_eng.attach(36);// 0 180             //recive a boolean valor 0= disengage 1=engage
    rotor_brakes.attach(38);//optional

    //electric pistons initialization
    pinMode(pCut, OUTPUT);
    pinMode(pCut1, OUTPUT);
    pinMode(pUnlock, OUTPUT);
    pinMode(pUnlock1, OUTPUT);
    pinMode(safe_stop, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(1000);                      // wait for a second
}