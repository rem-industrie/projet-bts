#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0)
  lcd.print("Mesure courant");
  lcd.setCursor(2, 1);
  lcd.print("Projet BTS 2023")
}