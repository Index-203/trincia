#include <Arduino.h>
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino_FreeRTOS.h>

#define MOWER_LEFT_PISTON_HEIGHT_PIN 40     //piston height cut
#define MOWER_RIGHT_PISTON_HEIGHT_PIN 41    //piston height cut
#define TRACK_LEFT_UNLOCK_PIN 42            //piston lock
#define TRACK_RIGHT_UNLOCK_PIN 43           //piston lock
#define SAFETY_STOP_PIN 44                  //safety stop

//servos
Servo throttle;
Servo brakes;
Servo shifter_sel;
Servo shifter_eng;
Servo track_unlock_right;
Servo track_unlock_left;
Servo mower_eng;
Servo mower_brakes;

//rf24
RF24 radio(7, 8); //CE, CSN
const byte address[6] = "00001";

//struct for data receiver
struct Data_Pack {
int throttle_value;
int shift_speed;
bool shift_eng;
int track_right;
int track_left;
bool mover_state;
};


void setup() {

    //servo initialization
    throttle.attach(22);            //var 0 180                   potentiometer
    brakes.attach(24);              //0 180                       by software
    shifter_sel.attach(28);         //var 0 180  r 0 1 2 3        receive r 0 1 2 3
    shifter_eng.attach(30);         //0 180                       by software & receive
    track_unlock_right.attach(32);  //var 0 180 3 pos             receive 3 valor pos 1 pos 2 pos 3
    track_unlock_left.attach(34);   //var 0 180  3 pos            receive 3 valor pos 1 pos 2 pos 3
    mower_eng.attach(36);           //0 180                       receive a boolean valor 0 = disengage 1 = engage
    mower_brakes.attach(38);        //optional

    //electric pistons initialization
    pinMode(MOWER_LEFT_PISTON_HEIGHT_PIN, OUTPUT);
    pinMode(MOWER_RIGHT_PISTON_HEIGHT_PIN, OUTPUT);
    pinMode(TRACK_LEFT_UNLOCK_PIN, OUTPUT);
    pinMode(TRACK_RIGHT_UNLOCK_PIN, OUTPUT);
    pinMode(SAFETY_STOP_PIN, OUTPUT);

    //rf24 connection initialization
    radio.begin();
    radio.setChannel(125);
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();

    //struct initialize
    struct Data_Pack initial_values{50, 0, LOW, 3, 3, LOW}; //pls remember Franz to insert correct value for servo control

    //send data pack value for debug
    Serial.begin(9600);
    Serial.println(initial_values.throttle_value);
    Serial.println(initial_values.shift_speed);
    Serial.println(initial_values.shift_eng);
    Serial.println(initial_values.track_right);
    Serial.println(initial_values.track_left);
    Serial.println(initial_values.mover_state);
}


void loop() {


}