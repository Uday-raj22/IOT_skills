// Blink multiple LEDs sequentially

// Define LED pins
const int red = 13;
const int blue = 12;
const int green = 11;

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pins as outputs
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
  // Turn the red LED on
  digitalWrite(red, HIGH);
  delay(100); // Wait for a second
  digitalWrite(red, LOW); // Turn the red LED off
  delay(100); // Wait for a second

  // Turn the blue LED on
  digitalWrite(blue, HIGH);
  delay(100); // Wait for a second
  digitalWrite(blue, LOW); // Turn the blue LED off
  delay(100); // Wait for a second

  // Turn the green LED on
  digitalWrite(green, HIGH);
  delay(100); // Wait for a second
  digitalWrite(green, LOW); // Turn the green LED off
  delay(100); // Wait for a second
}
