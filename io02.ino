// Combination of input and output code

// Define PWM parameters
#define PWM_FREQ 0x00FF    // PWM frequency -- 31.3 KHz
#define PWM_MODE 0         // Phase Correct PWM (0) or Fast PWM (1)
#define PWM_QTY 2          // Use both channels (A and B) in parallel

int guitarVal;
// int curTime = 0;
// int prevTime = 0;
// int max = 0;

void setup() {
  // Start serial output
  Serial.begin(115200);
 
  // Set IO pins
  pinMode(A0, INPUT);     // Input from guitar
  pinMode(6, OUTPUT);     // Feed offset into input
  // pinMode(9, OUTPUT);     // PWM output
  // pinMode(10, OUTPUT);    // PWM output

  // Set offset
  analogWrite(6, 38);

  // Setup PWM
  TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1));   // COM1A/B
  TCCR1B = ((PWM_MODE << 3) | 0x11);                          // WGM + prescaler clk/1
  // TIMSK1 = 0x20;                                              // Interrupt
  ICR1H = (PWM_FREQ >> 8);                                    // TOP value (frequency)
  ICR1L = (PWM_FREQ & 0xFF);                                  // 
  DDRB |= ((PWM_QTY << 1) | 0x02);                            // Turn on outputs
}


void loop() {
  // Read input
  guitarVal = analogRead(A0);
  // Moniter input
  Serial.println(guitarVal);
  // PWM Signals outputs
  //OCR1A = ((guitarVal + 0x8000) >> 8);  // unsigned high byte on pin 9
  //OCR1B = guitarVal;  // low byte on pin 10
  analogWrite(9, guitarVal);
  analogWrite(10, guitarVal);
}
