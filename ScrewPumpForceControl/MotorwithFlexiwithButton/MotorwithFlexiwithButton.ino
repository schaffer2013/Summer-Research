int flexPin = A0;
int modePin=7;
int dirPin = 8;
int pulsePin = 9;
int resistorVal = 4700;
int upperDBR = 6000;
int lowerDBR = 2000;

boolean buttonMode=false;
boolean lastButtonPress=false;

int delayMicros=45;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dirPin, OUTPUT);     //direction pin
  pinMode(pulsePin, OUTPUT); //step pin
  pinMode(modePin, INPUT);
}

void loop() {
  float flexVal = analogRead(flexPin);
  float flexVolt = flexVal * 5 / 1023;
  float flexR = resistorVal * (5 - flexVolt) / flexVolt;

  boolean buttonPress=digitalRead(modePin);
  if (buttonPress && !lastButtonPress && !buttonMode){
    buttonMode=true;
  }
  else if (buttonPress && !lastButtonPress && buttonMode){
    buttonMode=false;
  }
  lastButtonPress=buttonPress;
  
  //Serial.println(flexR);
  if (flexR > upperDBR && buttonMode) { //if less pressure, then turn motor CW
    digitalWrite(dirPin, HIGH);
    delayMicroseconds(delayMicros);
    Serial.println("CW");
    turnMotor();
  }
  else if (flexR < lowerDBR && buttonMode) { //if more pressure, then turn motor CCW
    digitalWrite(dirPin, LOW);
    delayMicroseconds(delayMicros);
    Serial.println("CCW");
    turnMotor();
  } 
  else {
    Serial.println("STABLE");
    delay(10);
  }

}

void turnMotor() {
  for (int i = 0; i < 50; i++) {
    digitalWrite(pulsePin, HIGH);
    delayMicroseconds(delayMicros);
    digitalWrite(pulsePin, LOW);
    delayMicroseconds(delayMicros);
  }
}



