/* 
Code to display Strings on I2C OLED dipslay as well as SPI OLED display, user has to update the user configuartion based on OLED used
by www.playwithcircuit.com
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans12pt7b.h>

// USER CONFIGURATION
#define OLED_TYPE 1  // 0 = I2C, 1 = SPI

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
#define OLED_RESET -1  // if SPI OLED display doesn't have Exposed reset pin theN its value is -1 else set it to 13 and connect it with pin 13
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
  // clear the Display
  display.clearDisplay();


  // draw Pixel on screen
  display.drawPixel(10, 10, WHITE);
  display.drawPixel(20, 10, WHITE);
  display.drawPixel(30, 10, WHITE);

  display.display();
  delay(3000);

  // Display the text on OLED
  display.clearDisplay();
  display.setCursor(0, 20);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("Hello OLED Display");
  display.display();
  delay(3000);

  // printing hex numbers
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.println("Number: ");
  display.println(255);
  display.println("HEX:");
  display.print(255, HEX);
  display.display();
  delay(3000);

  // using write function
  display.clearDisplay();
  display.setCursor(0, 0);
  display.write(3);
  display.write(0x20);
  display.write(4);
  display.write(0x20);
  display.write(5);
  display.write(0x20);
  display.write(6);
  display.write(0x20);
  display.display();
  display.setTextSize(1);
  delay(3000);

  // changing font
  display.clearDisplay();
  display.setFont(&FreeSans12pt7b);
  display.setCursor(0, 30);
  display.setTextColor(WHITE);
  display.print("FreeSans12pt7b");
  display.display();
  delay(3000);

  // Reset to default font
  display.setFont(NULL);

  // inverting the display
  display.clearDisplay();
  display.setCursor(0, 20);
  display.setTextSize(2);
  display.print("Invert Testing");
  display.display();
  delay(3000);

  display.invertDisplay(true);
  delay(3000);
  display.invertDisplay(false);

  // scrolling right
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Scroll Right");
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(3000);
  display.stopscroll();

  // scrolling left
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Scroll Left");
  display.display();
  display.startscrollleft(0x00, 0x07);
  delay(3000);
  display.stopscroll();

  // scrolling diagonally right
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Diag Right");
  display.display();
  display.startscrolldiagright(0x00, 0x07);
  delay(3000);
  display.stopscroll();

  // scrolling diagonally left
  display.clearDisplay();
  display.println("DiagLeft");
  display.display();
  display.startscrolldiagleft(0x00, 0x07);
  delay(3000);
  display.stopscroll();

  // clear the display
  display.clearDisplay();
  display.display();
}
