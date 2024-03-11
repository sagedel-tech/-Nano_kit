	// Define the pin to which the moisture sensor is connected
const int moistureSensorPin = A0;
// Define the pins for the LEDs
const int greenLEDPin = 8;
const int redLEDPin = 9;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  // Set LED pins as output
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  // Read the analog value from the moisture sensor
  int moistureLevel = analogRead(moistureSensorPin);

  // Print the moisture level to the serial monitor
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Check the moisture level and control LEDs accordingly
  if (moistureLevel < 500) { // Adjust this threshold as needed
    digitalWrite(greenLEDPin, HIGH); // Green LED ON
    digitalWrite(redLEDPin, LOW);    // Red LED OFF
  } else {
    digitalWrite(greenLEDPin, LOW);  // Green LED OFF
    digitalWrite(redLEDPin, HIGH);  // Red LED ON
  }

  // Add a delay to avoid flooding the serial monitor
  delay(1000);
}

