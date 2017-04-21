int tempSensor;
int moistureSensor=0;
int pumpPin=3;
int pumpPin2=4;

const long interval = 90000;
unsigned long previousMillis = 0;
int pinState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(tempSensor, INPUT);
  pinMode(moistureSensor, INPUT);
}

void loop() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (pinState == LOW) {
      pinState = HIGH;
    } else {
      pinState = LOW;
    }
    digitalWrite(pumpPin, pinState);
    digitalWrite(pumpPin2, pinState);
  }
//  digitalWrite(pumpPin, HIGH);
//  digitalWrite(pumpPin2, HIGH);
  
  int temmpValue = analogRead(tempSensor);
  int moistureValue = analogRead(moistureSensor);
  delay(1000);
  Serial.println("Moisture Value" + moistureValue);
  if (moistureValue < (300)) {
   Serial.println(moistureValue);
  Serial.println("ALERT!!!!!!!! WATER LEVEL TOO LOW");
  }
  if (temmpValue < 30) {
  Serial.println("ALERT!!!!!!! TEMP TOO LOW");
  }
  if (temmpValue>50 ) {
  Serial.println("ALERT!!!!!!! TEMP TOO HIGH");
  }
}
