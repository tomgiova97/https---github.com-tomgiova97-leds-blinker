#define PIN_1 D5
#define PIN_2 D6

#define BLINK_TIME_1_MS 1000
#define BLINK_TIME_2_MS 2000
#define GCD gcd(BLINK_TIME_2_MS, BLINK_TIME_1_MS)

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);

  digitalWrite(PIN_1, HIGH);
  digitalWrite(PIN_2, HIGH);
}

int counter = 1;

void loop() {
  delay(GCD);
  if (isTimeMultipleOfBlinkTime(counter * GCD, BLINK_TIME_1_MS)) {
    switchLedState(PIN_1);
  }  
  if (isTimeMultipleOfBlinkTime(counter * GCD, BLINK_TIME_2_MS)) {
  switchLedState(PIN_2);
  }  
  counter ++;
}

// Function to calculate the "greattest common divisor"
// between two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isTimeMultipleOfBlinkTime(long time, long blink_time) {
  return (time % blink_time == 0);
}

void switchLedState(uint8_t pin) {
  if (digitalRead(pin) == HIGH) {
    digitalWrite(pin, LOW); 
  }
  else {digitalWrite(pin, HIGH);}
}

