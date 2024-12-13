int yellowLed = 3;
int redLed = 4;
int greenLed = 8;
int buzzer1 = 5; 
int buzzer2 = 6; 
int gasPin = A0;
int flamePin = 2;

int gasSensorThres = 400;

void setup() {
  pinMode(yellowLed, OUTPUT);  
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(gasPin, INPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  int gasSensor = analogRead(gasPin);
  int flameSensor = digitalRead(flamePin);
  
  Serial.print("gasPin Value: ");
  Serial.println(gasSensor);
  Serial.print("flamePin Value: ");
  Serial.println(flameSensor);
  delay(1000);
  
  if (gasSensor > gasSensorThres  && flameSensor==LOW){
   digitalWrite(yellowLed, HIGH);
    digitalWrite(buzzer1, HIGH);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer2, HIGH);
    digitalWrite(greenLed, LOW);
  }
   else if (gasSensor > gasSensorThres)
  {
    digitalWrite(yellowLed, HIGH);
    digitalWrite(buzzer1, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer2, LOW);
    digitalWrite(greenLed, LOW);
  }
  else if (flameSensor==LOW){ // HIGH MEANS NO FLAME
    digitalWrite(yellowLed, LOW);
    digitalWrite(buzzer1, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer2, HIGH);
    digitalWrite(greenLed, LOW);
    }
  
  else
  {
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, LOW);
    digitalWrite(greenLed, HIGH);    
  }
}
