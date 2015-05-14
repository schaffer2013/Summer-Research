/*
microstep driver ST-M5045
Pul+ goes to +5V
Pul- goes to Arduino Pin 9
Dir+ goes to +5V
Dir- goes to to Arduino Pin 8
Enable+ to nothing
Enable- to nothing
*/

int sensorPin = A3;
int sensorValue = 0;

void setup() {                
  pinMode(8, OUTPUT);     //direction pin
  pinMode(9, OUTPUT); //step pin
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue,0,1023,3600,1);
  digitalWrite(9, HIGH);
  delayMicroseconds(sensorValue);          
  digitalWrite(9, LOW); 
  delayMicroseconds(sensorValue);
 }
