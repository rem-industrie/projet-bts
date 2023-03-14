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
  lcd.print("Arduino");
  lcd.setCursor(2, 1);
  lcd.print("GetStarted.com")

  lcd.clear();
  lcd.print("DIYables");
  lcd.setCursor(0, 1);
  lcd.print("www.diyables.io")
  delay(2000);
}