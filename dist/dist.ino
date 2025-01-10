// Pin Definitions
const int trigPin = 9;   // Trigger pin for ultrasonic sensor
const int echoPin = 10;  // Echo pin for ultrasonic sensor
const int redPin = 11;   // Red pin for RGB LED
const int greenPin = 12; // Green pin for RGB LED
const int bluePin = 13;  // Blue pin for RGB LED
const int buzzerPin = 8; // Buzzer pin

// Variables
long duration;
int distance;

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor to measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = duration * 0.0344 / 2;

  // Conditional statements for distance
  if (distance <= 10) { // Distance is less than or equal to 10cm
    digitalWrite(redPin, HIGH);   // Red LED ON
    digitalWrite(greenPin, LOW);  // Green LED OFF
    digitalWrite(bluePin, LOW);   // Blue LED OFF
    tone(buzzerPin, 1000);        // Buzzer ON at 1000Hz
    delay(500);                   // Wait for half a second
    digitalWrite(redPin, LOW);    // Red LED OFF
    noTone(buzzerPin);            // Buzzer OFF
    delay(500);                   // Wait for half a second
  }
  else if (distance > 10 && distance <= 20) { // Distance between 10cm and 20cm
    digitalWrite(redPin, LOW);    // Red LED OFF
    digitalWrite(greenPin, LOW);  // Green LED OFF
    digitalWrite(bluePin, HIGH);  // Blue LED ON
    delay(500);                   // Wait for half a second
    digitalWrite(bluePin, LOW);   // Blue LED OFF
    delay(500);                   // Wait for half a second
  }
  else if (distance > 20) { // Distance is greater than 20cm
    digitalWrite(redPin, LOW);    // Red LED OFF
    digitalWrite(greenPin, HIGH); // Green LED ON
    digitalWrite(bluePin, LOW);   // Blue LED OFF
    delay(500);                   // Wait for half a second
    digitalWrite(greenPin, LOW);  // Green LED OFF
    delay(500);                   // Wait for half a second
  }
}