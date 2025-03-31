// Combination of input and output code

// Define PWM parameters
#define PWM_FREQ 0x00FF    // PWM frequency (sets TOP value)
#define PWM_MODE 0         // Phase Correct PWM (0) or Fast PWM (1)
#define PWM_QTY 2          // Use both channels (A and B)

int guitarVal;
int curTime = 0;
int prevTime = 0;
int max = 0;

void setup() {
  // Start serial output
  Serial.begin(115200);

  // Setup PWM using Timer1
 
  // Set input pins
  pinMode(A0, INPUT);
  // Set output pins
  pinMode(6, OUTPUT); // Feed offset into input
  pinMode(9, OUTPUT); // PWM output
  pinMode(10, OUTPUT); // PWM output

  // Set offset
  analogWrite(6, 38);

  // Setup Timer1 for PWM
  TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1)); // COM1A/B
  TCCR1B = ((PWM_MODE << 3) | 0x11);  // WGM + prescaler clk/1
  ICR1H = (PWM_FREQ >> 8);            // TOP value (frequency)
  ICR1L = (PWM_FREQ & 0xFF);


  // Initial duty cycles
  OCR1A = PWM_FREQ / 2;  // 50% duty cycle on pin 9
  OCR1B = PWM_FREQ / 4;  // 25% duty cycle on pin 10
}


void loop() {
  // Read input
  guitarVal = analogRead(A0);
  // Moniter input
  Serial.println(guitarVal);

  // Nothing needed here; PWM runs automatically via hardware
}
