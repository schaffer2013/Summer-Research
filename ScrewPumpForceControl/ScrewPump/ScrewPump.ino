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
int backwardPin = 2;
int forwardPin=3;
int limitPin=7;
int currentStep=0

void setup() {                
  pinMode(backwardPin, INPUT);
  pinMode(forwardPin, INPUT);
  pinMode(limitPin, INPUT);
  pinMode(8, OUTPUT);     //direction pin
  pinMode(9, OUTPUT); //step pin
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  //attachInterrupt(1,kill,RISING) ;
}

//void swap(){
//  if(digitalRead(8) == HIGH){
//    digitalWrite(8, LOW);
//  }
//  else{
//    digitalWrite(8, HIGH);
//  }
//}

void loop() {
  if (digitalRead(backwardPin)){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delayMicroseconds(500);          
    digitalWrite(9, LOW); 
    delayMicroseconds(500);
  }
  if (digitalRead(forwardPin)&!digitalRead(limitPin)){
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    delayMicroseconds(500);          
    digitalWrite(9, LOW); 
    delayMicroseconds(500);
  }
  //  if (!digitalRead(backwardPin)&!digitalRead(forwardPin)){
  //    delay(10);
  //  }
}




