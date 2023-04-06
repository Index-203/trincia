#include <Arduino.h>
#include <Servo.h>
#include <RF24.h>
#include <Arduino_FreeRTOS.h>

#define p_mower_high_left 40    // piston height cut
#define p_mower_high_right 41   // piston height cut
#define p_unlock_left 42        // piston lock
#define p_unlock_right 43       // piston lock
#define safety_stop 43          // safety stop

// servos
Servo throttle;
Servo brakes;
Servo shifter_sel;
Servo shifter_eng;
Servo track_unlock_right;
Servo track_unlock_left;
Servo mower_eng;
Servo mower_brakes;

void setup() {

    // servo initialization
    throttle.attach(22);            // var 0 180                   potentiometer
    brakes.attach(24);              // 0 180                       by software
    shifter_sel.attach(28);         // var 0 180  r 0 1 2 3        receive r 0 1 2 3
    shifter_eng.attach(30);         // 0 180                       by software & receive
    track_unlock_right.attach(32);  // var 0 180 3 pos             receive 3 valor pos 1 pos 2 pos 3
    track_unlock_left.attach(34);   // var 0 180  3 pos            receive 3 valor pos 1 pos 2 pos 3
    mower_eng.attach(36);           // 0 180                       receive a boolean valor 0 = disengage 1 = engage
    mower_brakes.attach(38);        // optional

    // electric pistons initialization
    pinMode(p_mower_high_left, OUTPUT);
    pinMode(p_mower_high_right, OUTPUT);
    pinMode(p_unlock_left, OUTPUT);
    pinMode(p_unlock_right, OUTPUT);
    pinMode(safety_stop, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on (HIGH is the voltage level)
    delay(1000);                            // wait for a second
    digitalWrite(LED_BUILTIN, LOW);     // turn the LED off by making the voltage LOW
    delay(1000);                            // wait for a second
}