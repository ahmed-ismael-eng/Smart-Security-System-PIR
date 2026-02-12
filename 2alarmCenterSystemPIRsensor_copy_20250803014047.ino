#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int pirPin     = 7;
const int greenLED1  = 2;
const int greenLED2  = 3;
const int blueLED1   = 4;
const int blueLED2   = 5;
const int redLED1    = 8;
const int redLED2    = 9;
const int buzzer     = 10;

void setup() {
  Serial.begin(9600);

  // OLED Init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("❌ OLED not found!");
    while (true);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("System Starting...");
  display.display();
  delay(2000);

  // Pin Modes
  pinMode(pirPin, INPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(greenLED2, OUTPUT);
  pinMode(blueLED1, OUTPUT);
  pinMode(blueLED2, OUTPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    Serial.println("🚨 Motion Detected!");

    // Turn off green
    digitalWrite(greenLED1, LOW);
    digitalWrite(greenLED2, LOW);

    // OLED alert
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("🚨 ALERT!");
    display.setTextSize(1);
    display.println("Motion Detected!");
    display.display();

    // Police effect + siren
    for (int i = 0; i < 4; i++) {
      digitalWrite(redLED1, HIGH);
      digitalWrite(redLED2, HIGH);
      digitalWrite(blueLED1, LOW);
      digitalWrite(blueLED2, LOW);
      tone(buzzer, 880);
      delay(150);

      digitalWrite(redLED1, LOW);
      digitalWrite(redLED2, LOW);
      digitalWrite(blueLED1, HIGH);
      digitalWrite(blueLED2, HIGH);
      tone(buzzer, 660);
      delay(150);
    }

    noTone(buzzer);
    digitalWrite(redLED1, LOW);
    digitalWrite(redLED2, LOW);
    digitalWrite(blueLED1, LOW);
    digitalWrite(blueLED2, LOW);

  } else {
    Serial.println("✅ No motion.");

    // OLED safe
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("✅ SAFE");
    display.setTextSize(1);
    display.println("No motion detected");
    display.display();

    // Green LEDs ON
    digitalWrite(greenLED1, HIGH);
    digitalWrite(greenLED2, HIGH);

    // Others OFF
    digitalWrite(redLED1, LOW);
    digitalWrite(redLED2, LOW);
    digitalWrite(blueLED1, LOW);
    digitalWrite(blueLED2, LOW);

    // Safe beep
    tone(buzzer, 300);
    delay(100);
    noTone(buzzer);
    delay(400);
  }

  delay(300); // Short pause between reads
}
