#include <Servo.h>

Servo mioServo;  // Crea l'oggetto servo

int pinJoystickX = A0;  // Pin analogico per l'asse Y del joystick
int valJoystick;  // Valore letto dal joystick
int posizioneCorrente = 0;  // Posizione corrente del servo
int gradi_start = 0;
int gradi_end = 180;
int gradi_mid_start, gradi_mid_end;

void setup() {
  mioServo.attach(9);  // Collega il servo al pin 9
  mioServo.write(posizioneCorrente);  // Imposta la posizione iniziale del servo
  Serial.begin(9600);
}

void loop() {
  gradi_mid_start = gradi_end/2 - 5;
  gradi_mid_end = gradi_end/2 + 5;
  valJoystick = analogRead(pinJoystickX);  // Legge la posizione dell'asse Y del joystick
  valJoystick = map(valJoystick, 0, 1023, gradi_end, gradi_start);  // Scala il valore per il servo

  if (valJoystick >= gradi_mid_start && valJoystick <= gradi_mid_end) // basta anche solo valJoystick==90 il mio servo non ce la faceva  -- fa stare fermo il servo (circa)
  {
    mioServo.write(0);
  }
  else if (valJoystick > posizioneCorrente) 
  {
    posizioneCorrente++;
  } 
  else if (valJoystick < posizioneCorrente) 
  {
    posizioneCorrente--;
  }
  
  
  mioServo.write(posizioneCorrente); // Muove il servo alla posizione richiesta
  Serial.print("Valore del joystick - pos corrente: ");
  Serial.println(posizioneCorrente);
  delay(100);  // Aggiunge un ritardo per rallentare il movimento del servo

}
