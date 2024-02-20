#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Test LCD");
  lcd.setCursor(1,0);
  lcd.println("Baris Kedua");

  Serial.println("Test LCD");

  delay(2000);
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ini Teks");
}
