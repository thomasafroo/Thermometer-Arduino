// Displaying temperature data from a thermistor on a LCD display

#include <LiquidCrystal.h>
int tempPin = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempReading = analogRead(tempPin);

  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.000000086741 * tempK * tempK)) * tempK); // temp Kelvin
  float tempC = tempK - 273.15;
  float tempF = tempF = (tempC * 9.0) / 5.0 + 32.0; // convert celsius to fahrenheit

  // Display Temperature in C
  lcd.setCursor(0, 0);
  lcd.print("Temp        C ");
  // Display temperature in F
  // lcd.print("Temp           F  ");
  lcd.setCursor(6, 0);
  // display temperature in C
  lcd.print(tempC);
  lcd.setCursor(0, 1);
  // display temperature in F
  lcd.print("            F ");
  lcd.setCursor(6,1);
  lcd.print(tempF);
  delay(500);
}
