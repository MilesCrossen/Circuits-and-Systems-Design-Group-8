// function.ino
// based function which can be replaced with tuner 
// just prints Tuner Mode

#include "U8glib.h"


void func_setup() {
  // Initialize the OLED screen
  screen.setColorIndex(255);  // Set the color to white
  screen.setFont(u8g_font_unifont);  // Use a standard font
}

void func_loop() {
  // Display "Tuner Mode" on the OLED screen
  screen.firstPage();
  do {
    screen.drawStr(0, 22, "Tuner Mode");
  } while (screen.nextPage());

  delay(1000);  // Refresh rate (display message every second)
}
