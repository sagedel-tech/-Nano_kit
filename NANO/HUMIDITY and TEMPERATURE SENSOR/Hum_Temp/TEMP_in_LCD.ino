#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
}

void loop() {
  float humidity = dht.readHumidity();    // Read humidity
  float temperature = dht.readTemperature();  // Read temperature in Celsius

  if (isnan(humidity) || isnan(temperature)) {  // Check if any reads failed
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  lcd.setCursor(12,0);  // Set the cursor to the 12th column of the first row
  lcd.print(temperature);  // Print temperature
  lcd.setCursor(9,1);  // Set the cursor to the 9th column of the second row
  lcd.print(humidity);  // Print humidity

  delay(2000);  // Delay for 2 seconds
}

