/* (C)2021 Benji
 *  Version 0.9

    Sol is an alarm clock that simulates the rising sun in the morning.
    
    Parts:
      Arduino Mega
      2.8" TFT Touchscreen
      
      NEEDED:
        DS3231 clock
        LEDs
*/

#define DEBUG

#include <Elegoo_GFX.h>     // Core graphics library
#include <Elegoo_TFTLCD.h>  // Hardware-specific library
#include <DS3231.h>         // clock library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_RESET  A4 // Can alternately just connect to Arduino's reset pin (PC6)
#define LCD_CS A3     // Chip Select goes to Analog 3
#define LCD_CD A2     // Command/Data goes to Analog 2 //sometimes: LCD_RS
#define LCD_WR A1     // LCD Write goes to Analog 1
#define LCD_RD A0     // LCD Read goes to Analog 0

// Init the display
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

// To store the actual time
Time now;

// Assign human-readable names to some common 16-bit color values:
#define BLACK     0x0000
#define DARKGREY  0x7BEF
#define LIGHTGREY 0xBDF7
#define WHITE     0xFFFF
#define BROWN     0x79E0
#define RED       0xF800
#define GREEN     0x07E0
#define BLUE      0x001F
#define CYAN      0x07FF
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define ORANGE    0xFBE0

void setup() {
  
  Serial.begin(9600);
  Serial.println("Serial initialized");
/*
  // Initialize the rtc object
  rtc.begin();
  Serial.println("rtc initialized");

  // Get the time
  now = rtc.getTime();
  unixTime = rtc.getUnixTime(now);
  Serial.println("Time taken");
  Serial.print("UNIX: ");
  Serial.println(rtc.getUnixTime(rtc.getTime()));
  Serial.print("time: ");
  Serial.println(rtc.getTimeStr());
*/

  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(1);
  Serial.println("tft initialized");

  
  //print all the static text and stuff
  tft.fillScreen(BLACK);
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.setCursor(10, 10);
  tft.print("You can play for:");
  tft.drawFastHLine(0, tft.height()/2, tft.width(), YELLOW);

  
  Serial.println();
  Serial.println("SETUP finished");
#ifdef DEBUG
  Serial.println("DEBUG activated");
#else
  Serial.println("DEBUG deactivated");
#endif
  
}

void loop() {

}
