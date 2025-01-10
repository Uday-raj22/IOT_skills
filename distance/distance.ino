  int green=13;
  int blue =11;
  int red=12;
  int trigpin=6;
  int echopin=7;
  int buzzer=3;
  int sound=250;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  long duration, distance;
  digitalWrite(trigpin, LOW);  
  delayMicroseconds(2);        
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10);  
  digitalWrite(trigpin, LOW);
  duration=pulseIn(echopin, HIGH);
  distance=(duration/2)/29.1;

  if (distance<=10){
    digitalWrite(red, HIGH);
    sound=250;
  }
  else {
    digitalWrite(red, LOW);
  }
  if (distance<=20 && distance>=10){
    digitalWrite(blue, HIGH);
    sound=260;
  }
  else {
    digitalWrite(blue, LOW);
  }
    if (distance>=20){
    digitalWrite(green, HIGH);
    sound=270;
  }
  else {
    digitalWrite(green, LOW);
  }
  delay(500);
}
