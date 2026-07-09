// ── Libraries ────────────────────────────────
#include <LiquidCrystal.h>

// ── LCD pins ─────────────────────────────────
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// ── Pin definitions ──────────────────────────
#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_GREEN 11
#define LED_YELLOW 12
#define LED_RED 13
#define BUZZER 8

// ── Setup ────────────────────────────────────
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Alarm Ready...");

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  delay(2000);
  lcd.clear();
}

// ── Get distance in cm (averaged) ────────────
long getDistance() {
  long total = 0;
  int samples = 5;

  for (int i = 0; i < samples; i++) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duration == 0) {
      total += 999;
    } else {
      total += duration * 0.034 / 2;
    }
    delay(10);
  }

  return total / samples;
}

// ── Main loop ────────────────────────────────
void loop() {
  long distance = getDistance();

  // Print to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Update LCD line 1 — distance
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Turn off everything first
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  noTone(BUZZER);

  // Alert zones
  if (distance > 30) {
    digitalWrite(LED_GREEN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE    ");

  } else if (distance > 15) {
    digitalWrite(LED_YELLOW, HIGH);
    tone(BUZZER, 1000, 100);
    lcd.setCursor(0, 1);
    lcd.print("Status: WARNING ");

  } else {
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER, 2000, 500);
    lcd.setCursor(0, 1);
    lcd.print("Status: DANGER! ");
  }

  delay(100);
}
