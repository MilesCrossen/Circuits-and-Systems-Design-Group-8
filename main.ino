//main.ino toggles between tuner mode and effects mode for screen functions

#include <U8glib.h>
// Variables for pins
int D0 = 13;
int D1 = 11;
int RES = 8;
int DC = 9;
int CS = 10;

// Variable for the screen
U8GLIB_SSD1306_128X64 screen(D0, D1, CS, DC, RES);

// Variable to switch between functions
int currentMode = 0;  // 0 = function, 1 = frequency display

void setup() {
  Serial.begin(9600);


  pinMode(A0, INPUT);  // If using analog input, for example
  pinMode(A1, INPUT);  // If using analog input, for example

  // Initial display message
  Serial.println("Switching between functions...");
}

void loop() {

  currentMode = analogRead(A1);
  if (currentMode < 800) {
    // Call the loop in function.ino
    func_loop();
  }

    // After a while, switch to frequency display
  if (currentMode >= 800) {
    // Call the loop in frequencyDisplay.ino
    freq_loop();
    }
}
