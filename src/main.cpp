#include <Arduino.h>
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino_FreeRTOS.h>

#define MOWER_PISTON_HEIGHT_PIN_1 40     //piston height cut
#define MOWER_PISTON_HEIGHT_PIN_2 41    //piston height cut
#define TRACK_UNLOCK_PIN_1 42            //piston lock
#define TRACK_UNLOCK_PIN_2 43           //piston lock
#define SAFETY_STOP_PIN 44                  //safety stop
//alessia line
//servos
Servo throttle;
Servo brakes;
Servo shifter_selector;
Servo shifter_clutch;
Servo track_right_mode;
Servo track_left_mode;
Servo mower_engage;
Servo mower_brakes;

//rf24
RF24 radio(7, 8); //CE, CSN
const byte address[6] = "00001";

//struct for data receiver
struct Data_Pack {
int throttle_value;
int shifter_gear_value;
bool shifter_clutch_value;
int track_right_mode_value;
int track_left_mode_value;
bool mower_engage_value;
};


void setup() {

    //servo initialization
    throttle.attach(22);            //var 0 180                   potentiometer
    brakes.attach(24);              //0 180                       by software -> on when shifter on 0 otherwise off
    shifter_selector.attach(28);    //var 0 180  r 0 1 2 3        receive r 0 1 2 3
    shifter_clutch.attach(30);      //0 180                       by software & receive
    track_right_mode.attach(32);    //var 0 180 3 pos             receive 3 values pos 1 pos 2 pos 3
    track_left_mode.attach(34);     //var 0 180  3 pos            receive 3 values pos 1 pos 2 pos 3
    mower_engage.attach(36);        //0 180                       receive a boolean valor 0 = disengage 1 = engage
    mower_brakes.attach(38);        //optional                    by software -> on when mower_engage on 0 otherwise off

    //electric pistons initialization
    pinMode(MOWER_PISTON_HEIGHT_PIN_1, OUTPUT);
    pinMode(MOWER_PISTON_HEIGHT_PIN_2, OUTPUT);
    pinMode(TRACK_UNLOCK_PIN_1, OUTPUT);
    pinMode(TRACK_UNLOCK_PIN_2, OUTPUT);
    pinMode(SAFETY_STOP_PIN, OUTPUT);

    //rf24 connection initialization
    radio.begin();
    radio.setChannel(125);
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MAX);
    radio.startListening();

    //struct initialize
    struct Data_Pack initial_values{50, 0, LOW, 3, 3, LOW}; //pls remember Franz to insert correct value for servo control

    //send data pack value for debug
    Serial.begin(9600);
    Serial.println(initial_values.throttle_value);
    Serial.println(initial_values.shifter_gear_value);
    Serial.println(initial_values.shifter_clutch_value);
    Serial.println(initial_values.track_right_mode_value);
    Serial.println(initial_values.track_left_mode_value);
    Serial.println(initial_values.mower_engage_value);
    Serial.end();
}


void loop() {


}