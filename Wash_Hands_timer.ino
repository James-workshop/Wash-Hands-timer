// For a connection via I2C using the Arduino Wire include:
#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SH1106Wire.h"        // legacy: #include "SSD1306.h"

// Initialize the OLED display using Arduino Wire:
SH1106Wire display(0x3c, D3, D4);     // ADDRESS, SDA, SCL

// include custom images
#include "images.h"
// include custom Font
#include "fonts_BIG.h"


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  pinMode(D2, OUTPUT);   
  digitalWrite(D2, HIGH);     //power on OLED
  delay(500);
  
  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
}

void loop() {
  display.clear();
  delay(10);
  
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 0, "Boot up......OK");
  display.display();
  delay(1000);
  
  display.clear();
  delay(10);
  display.drawXbm(0, 0, Wash_hands_width, Wash_hands_height, Wash_hands_bits);
  display.display();
  delay(2000);
  
  display.drawXbm(32, 32, ready_width, ready_height, ready_bits);
  display.display();
  delay(2000);
  
  display.clear();
  delay(10);
  display.setFont(SansSerif_plain_50);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  
  for (int i=30; i>0; i--) {
      display.drawString(64, 0, String(i) + " s");
      display.display();
      delay(1000);
      display.clear();
  }
  display.clear();
  delay(10);  
  display.drawString(64, 0, "0 s");
  display.display();
  delay(5000);    

  display.clear();
  delay(10);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 24, "Power Off");
  display.display(); 
  delay(5000);
  
  display.clear();
  delay(10);
  display.display();
  delay(100);
  ESP.deepSleep(0); 
}
