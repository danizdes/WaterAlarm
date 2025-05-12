// Declerations

const int buzzerPin = 2;
const int ledPin1 = 3;
const int ledPin2 = 4;
const int buttonPin = 7;

const int sensorPin = A0;
int sensorValue;

int minimumWaterLevelRequired = 100;

int buttonPressed = false;
void noAlarm() {
  digitalWrite(ledPin2, HIGH);
  tone(buzzerPin, 400);
  delay(700);
  digitalWrite(ledPin2, LOW);
  noTone(buzzerPin);
  delay(700);
}

void alarmDetected() {
  digitalWrite(ledPin1, HIGH);
  tone(buzzerPin, 400);
  delay(200);
  noTone(buzzerPin);
  digitalWrite(ledPin1, LOW);
  delay(200);
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(buttonPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonPressed = digitalRead(buttonPin);
  sensorValue = analogRead(sensorPin);

  Serial.println(buttonPressed);

  if (sensorValue > minimumWaterLevelRequired) {
    alarmDetected();
  }

  else {
    noAlarm();
  }
  

}
