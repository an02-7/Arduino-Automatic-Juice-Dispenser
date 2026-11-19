/*
 * Project: Automatic Contactless Juice Dispenser
 * MCU: Arduino Uno (ATmega328P)
 * Author: Afnan Aref (Saba University - Mechatronics Engineering)
 */

#define TRIGGER_PIN 5
#define ECHO_PIN    4
#define RELAY_PIN   6

float duration = 0;
float distance = 0;

void measure_distance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 200.0) / 20000.0;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  delay(2000);
}

void loop() {
  measure_distance();

  // Activate relay (active-LOW) when cup is detected within 5 cm
  if (distance < 5) {
    digitalWrite(RELAY_PIN, LOW);
  } else {
    digitalWrite(RELAY_PIN, HIGH);
  }

  delay(500);
}
