int flexPin = A0;
int dirPin = 8;
int pulsePin = 9;
int resistorVal = 4700;
int upperDBR = 6000;
int lowerDBR = 2000;

int delayMicros=45;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dirPin, OUTPUT);     //direction pin
  pinMode(pulsePin, OUTPUT); //step pin
}

void loop() {
  // put your main code here, to run repeatedly:
  float flexVal = analogRead(flexPin);
  float flexVolt = flexVal * 5 / 1023;
  float flexR = resistorVal * (5 - flexVolt) / flexVolt;
  //Serial.println(flexR);
  if (flexR > upperDBR) { //if less pressure, then turn motor CW
    digitalWrite(dirPin, HIGH);
    delayMicroseconds(delayMicros);
    Serial.println("CW");
    turnMotor();
  }
  else if (flexR < lowerDBR) { //if more pressure, then turn motor CCW
    digitalWrite(dirPin, LOW);
    delayMicroseconds(delayMicros);
    Serial.println("CCW");
    turnMotor();
  } else {
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
