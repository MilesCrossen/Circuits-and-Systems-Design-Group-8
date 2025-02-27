// Rowan Turner, 22302171
// Last Updated: 27/02/25
// Module that displays "Off!" or "On!" on the MDOB128064BV-WS OLED screen, alternates in 5-second intervals

#include "U8glib.h"

// Variables for pins
int D0 = 13;
int D1 = 11;
int RES = 8;
int DC = 9;
int CS = 10;
// Variable for the screen
U8GLIB_SSD1306_128X64 screen(D0, D1, CS, DC, RES);
int drawOn = 0, buttonOn = 0;

void draw(int freq) {
  if (freq > 100) {
    screen.drawStr(0, 22, "On!");
  } else {
    screen.drawStr(0, 22, "Off!");
  }
}

void setup() {
  // Screen setup
  screen.setColorIndex(255);
  screen.setFont(u8g_font_unifont);
  // Pin setups
  pinMode(RES, OUTPUT);
  pinMode(4, INPUT);
  pinMode(7, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (buttonOn == 0) {
    digitalWrite(7, LOW);
    buttonOn = 1;
  } else {
    digitalWrite(7, HIGH);
    buttonOn = 0;
  }

  if (digitalRead(4) == HIGH) {
    drawOn = 123;
  } else {
    drawOn = 12;
  }

  screen.firstPage();
  do {
    draw(drawOn);
  } while (screen.nextPage());

  delay(5000);
}
