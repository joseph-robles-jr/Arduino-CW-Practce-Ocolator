#define DIT_PIN 2
#define DAH_PIN 3
#define OUTPUT_PIN 13 // Built-in LED pin on most Arduino boards
#define SPEAKER_PIN 9
#define POT_PIN A0 // Potentiometer connected to analog pin A0

int ditState = 0;
int dahState = 0;
int lastDitState = 0;
int lastDahState = 0;
bool isSending = false;

unsigned long ditTime = 100; // Initial duration of a dit in milliseconds
unsigned long dahTime = 3 * ditTime; // Initial duration of a dah in milliseconds
unsigned long pauseTime = ditTime; // Initial duration of a pause between elements
unsigned int toneFrequency = 1000; // Frequency of the tone in Hertz (1 kHz)

void setup() {
  pinMode(DIT_PIN, INPUT_PULLUP);
  pinMode(DAH_PIN, INPUT_PULLUP);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, LOW);
}

void loop() {
  // Read the potentiometer value and map it to a suitable range for ditTime
  int potValue = analogRead(POT_PIN);
  ditTime = map(potValue, 0, 1023, 50, 500); // Map pot value to range 50ms - 500ms
  dahTime = 3 * ditTime; // Dah time is three times the dit time
  pauseTime = ditTime; // Pause time is equal to the dit time
  
  ditState = digitalRead(DIT_PIN);
  dahState = digitalRead(DAH_PIN);
  
  if (ditState == LOW && dahState == LOW) {
    // Both paddles pressed
    iambicMode();
  } else {
    // Single paddle pressed
    if (ditState == LOW && lastDitState == HIGH) {
      sendDit();
    }
    if (dahState == LOW && lastDahState == HIGH) {
      sendDah();
    }
  }

  lastDitState = ditState;
  lastDahState = dahState;
}

void sendDit() {
  digitalWrite(OUTPUT_PIN, HIGH);
  tone(SPEAKER_PIN, toneFrequency);
  delay(ditTime);
  digitalWrite(OUTPUT_PIN, LOW);
  noTone(SPEAKER_PIN);
  delay(pauseTime);
}

void sendDah() {
  digitalWrite(OUTPUT_PIN, HIGH);
  tone(SPEAKER_PIN, toneFrequency);
  delay(dahTime);
  digitalWrite(OUTPUT_PIN, LOW);
  noTone(SPEAKER_PIN);
  delay(pauseTime);
}

void iambicMode() {
  while (digitalRead(DIT_PIN) == LOW && digitalRead(DAH_PIN) == LOW) {
    sendDit();
    delay(pauseTime);
    sendDah();
    delay(pauseTime);
  }
}
