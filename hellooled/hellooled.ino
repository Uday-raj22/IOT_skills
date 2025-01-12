#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  // Clear the display buffer
  display.clearDisplay();
  // Set the text color and background color
  display.setTextColor(BLACK,WHITE);
  display.setTextSize(1.5);
  // Set the cursor position
  display.setCursor(0, 0);
  // Print "Hello World"
  display.println("HELLO");
  display.println("Varun And Uday");
  // Update the display
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // Nothing to do here
}