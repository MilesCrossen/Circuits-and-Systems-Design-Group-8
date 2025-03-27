// Rowan Turner, 22302171
// Last Updated: 27/02/25
// Module that displays a simulated frequency spectrogram on the MDOB128064BV-WS OLED screen

#include "U8glib.h"



// Time-based variables to simulate oscillation
unsigned long lastUpdate = 0;
float timeFactor = 0.5; // Controls speed of oscillation

// Simulate 10 frequency bands (each with random or varying amplitude)
int frequencyBands[10];

void drawSpectrogram() {
  screen.setFont(u8g_font_unifont);

  // Draw each frequency band as a vertical bar
  for (int i = 0; i < 10; i++) {
    // Random or oscillating amplitude for each frequency band
    int amplitude = (sin(timeFactor * i + millis() * 0.005) * 32) + 33; // Oscillates with varying amplitude

    // Map the amplitude to the screen height (from 0 to 64)
    amplitude = constrain(amplitude, 0, 64);

    // Draw the bar for the frequency band
    screen.drawBox(i * 12, 64 - amplitude, 10, amplitude);  // Display as bars
  }
}

void freq_setup() {
  // Screen setup
  screen.setColorIndex(255);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void freq_loop() {
  // Update the frequency bands every loop (simulating real-time updates)
  screen.firstPage();
  do {
    drawSpectrogram();
  } while (screen.nextPage());

  delay(100);  // Refresh rate for smoother display
}
