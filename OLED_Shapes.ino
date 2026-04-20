/* 
Code to display shapes on I2C OLED dipslay as well as SPI OLED display, user has to update the user configuartion based on OLED used
by www.playwithcircuit.com
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans12pt7b.h>

// USER CONFIGURATION
#define OLED_TYPE 0  // 0 = I2C, 1 = SPI

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C CONFIG
#if OLED_TYPE == 0
#define OLED_ADDR 0x3C
#define OLED_RESET -1  // I2C OLED display doesn't have Exposed reset pin
#endif


// SPI CONFIGURATIONS
#if OLED_TYPE == 1
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET -1  // if SPI OLED display doesn't have Exposed reset pin the its value is -1 else set it to 13 and connect in hardware
#endif

// DISPLAY OBJECT
#if OLED_TYPE == 0
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#else
Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  OLED_MOSI,
  OLED_CLK,
  OLED_DC,
  OLED_RESET,
  OLED_CS);
#endif




// this function display the name of function being used
void showTitle(const char *title) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 25);
  display.println(title);
  display.display();
  delay(1500);
}

// SETUP
void setup() {

  // this serial port is to display error, if occured during OLED init
  Serial.begin(9600);

  // begin
  #if OLED_TYPE == 0
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
      Serial.println("SSD1306 init failed");
      while (1)
        ;
    }
  #else
    if (!display.begin(SSD1306_SWITCHCAPVCC)) {

      Serial.println("SSD1306 init failed");
      while (1)
        ;
    }
  #endif
}

void loop() {

  // Drawing a line
  showTitle("drawLine()");
  display.clearDisplay();
  display.drawLine(0, 0, 127, 63, WHITE);
  display.display();
  delay(2000);

  // draw rectangle
  showTitle("drawRect()");
  display.clearDisplay();
  display.drawRect(20, 10, 80, 40, WHITE);
  display.display();
  delay(2000);

  // draw filled rectangle
  showTitle("fillRect()");
  display.clearDisplay();
  display.fillRect(20, 10, 80, 40, WHITE);
  display.display();
  delay(2000);

  // draw circle
  showTitle("drawCircle()");
  display.clearDisplay();
  display.drawCircle(64, 32, 20, WHITE);
  display.display();
  delay(2000);

  // draw filled circle
  showTitle("fillCircle()");
  display.clearDisplay();
  display.fillCircle(64, 32, 20, WHITE);
  display.display();
  delay(2000);

  // draw triangle
  showTitle("drawTriangle()");
  display.clearDisplay();
  display.drawTriangle(20, 10, 100, 10, 60, 50, WHITE);
  display.display();
  delay(2000);

  // draw filled triangle
  showTitle("fillTriangle()");
  display.clearDisplay();
  display.fillTriangle(20, 10, 100, 10, 60, 50, WHITE);
  display.display();
  delay(2000);

  // draw rounded rectangle
  showTitle("drawRoundRect()");
  display.clearDisplay();
  display.drawRoundRect(20, 10, 80, 40, 10, WHITE);
  display.display();
  delay(2000);

  // draw filled rounded rectangle
  showTitle("fillRoundRect()");
  display.clearDisplay();
  display.fillRoundRect(20, 10, 80, 40, 10, WHITE);
  display.display();
  delay(2000);
}