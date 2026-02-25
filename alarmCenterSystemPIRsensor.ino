#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LCD 
LiquidCrystal_I2C lcd(0x27, 16, 2);

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

  // LCD Init
  lcd.init();       
  lcd.backlight();  //  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Starting...");
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
    Serial.println(" Motion Detected!");

    // Turn off green
    digitalWrite(greenLED1, LOW);
    digitalWrite(greenLED2, LOW);

    // LCD alert
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" ALERT!");
    lcd.setCursor(0, 1);
    lcd.print("Motion Detected!");

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
    Serial.println(" No motion.");

    // LCD safe
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" SAFE");
    lcd.setCursor(0, 1);
    lcd.print("No motion");

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
