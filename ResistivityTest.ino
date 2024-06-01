#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);

const int sensorPin = A0;  // Analog input pin that senses Vout
int sensorValue = 0;       // sensorPin default value
double Vin = 5;             // Input voltage
double Vout = 0;            // Vout default value
double Rref = 1002;         // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
double R = 0;               // Tested resistors default value


void setup() {
  lcd.begin();
  Serial.begin(9600);  // Initialize serial communications at 9600 bps
}

void loop() {
  sensorValue = analogRead(sensorPin);      // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;        // Convert Vout to volts
  R = Rref * (1.0 / ((Vin / Vout) - 1.0));  // Formula to calculate tested resistor's value
  //rho = resistivity = 
  //rho = k * R
  //dimana R = Resistansi
  //k = geometrical factor
  //k = A/L
  //where A is the cross-sectional area perpendicular to the current; and L is the height of a prismatic or cylindrical concrete sample.
  double A = 32;
  double L = 20;
  double rho = (A/L)*R;
  
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Resistivity");
  lcd.setCursor(0, 1);
  lcd.print(rho);
}
