const int irSensorPin = 2;      // IR sensor connected to digital pin 2
const int touchSensorPin = 4;   // Touch sensor connected to digital pin 4
const int ledPin = 13;          // Built-in LED on most Arduino boards
const int buzzerPin = 8;        // Buzzer connected to digital pin 8

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(touchSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Ensure the LED is initially off
}

void loop() {
  int irSensorValue = digitalRead(irSensorPin);
  int touchSensorValue = digitalRead(touchSensorPin);

  if (touchSensorValue == HIGH) {
    // Touch sensor is triggered; make the buzzer produce sound
    playBuzzerSound();
  } else {
    noTone(buzzerPin); // Turn off the buzzer
  }

  if (irSensorValue == HIGH) {
    // IR sensor detects signals; make the LED blink
    blinkLED();
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
}

void playBuzzerSound() {
  tone(buzzerPin, 1000); // Play a 1 kHz tone on the buzzer
}

void blinkLED() {
  digitalWrite(ledPin, HIGH); // Turn on the LED
  delay(500); // Blink duration
  digitalWrite(ledPin, LOW); // Turn off the LED
  delay(500); // Delay before next blink
}
