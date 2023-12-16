#include <Servo.h>

Servo mioServo;  // Crea l'oggetto servo

int pinJoystickX = A0;  // Pin analogico per l'asse Y del joystick
int valJoystick;  // Valore letto dal joystick
int posizioneCorrente = 90;  // Posizione corrente del servo

void setup() {
  mioServo.attach(9);  // Collega il servo al pin 9
  mioServo.write(posizioneCorrente);  // Imposta la posizione iniziale del servo
  Serial.begin(9600);
}

void loop() {
  valJoystick = analogRead(pinJoystickX);  // Legge la posizione dell'asse Y del joystick
  valJoystick = map(valJoystick, 0, 1023, 0, 180);  // Scala il valore per il servo

  if (valJoystick >= 85 && valJoystick <= 95) // basta anche solo valJoystick==90 il mio servo non ce la faceva  -- fa stare fermo il servo (circa)
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
  Serial.print("Valore del joystick: ");
  Serial.println(posizioneCorrente);
  delay(15);  // Aggiunge un ritardo per rallentare il movimento del servo
}
