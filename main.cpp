#include <Keypad.h>
#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
float radius = 0, angle = 0, mu = 0, speed = 0;
int step = 0;

float g = 9.8;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Safe Speed");
  delay(1500);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {
      input += key;
      lcd.print(key);
    }

    else if (key == '#') {
      float value = input.toFloat();
      input = "";
      lcd.clear();

      if (step == 0) {
        radius = value;
        lcd.print("Angle:");
      }
      else if (step == 1) {
        angle = value;
        lcd.print("Friction:");
      }
      else if (step == 2) {
        mu = value;
        lcd.print("Speed:");
      }
      else if (step == 3) {
        speed = value;

        float theta = angle * PI / 180.0;
        float denom = (1 - mu * tan(theta));

        if (denom <= 0) {
          lcd.print("Math Error");
          delay(3000);
          resetSystem();
          return;
        }

        float safeSpeed = sqrt((radius * g * (tan(theta) + mu)) / denom);

        lcd.setCursor(0,0);
        lcd.print("Limit:");
        lcd.print(safeSpeed);

        lcd.setCursor(0,1);

        if (speed <= safeSpeed) {
          lcd.print("SAFE");
        } else {
          lcd.print("NOT SAFE");
        }

        delay(4000);
        resetSystem();
        return;
      }

      step++;
    }

    else if (key == '*') {
      input = "";
      lcd.clear();
    }
  }

  if (step == 0 && input == "") {
    lcd.setCursor(0,0);
    lcd.print("Radius:");
    lcd.setCursor(0,1);
  }
}

void resetSystem() {
  radius = angle = mu = speed = 0;
  step = 0;
  input = "";
  lcd.clear();
}