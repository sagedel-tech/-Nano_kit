const int ldrPin = 6;    // LDR sensor module connected to digital pin 6
const int relayPin = 3;  // Relay control pin connected to digital pin 3

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure relay is initially off
}

void loop() {
  int lightValue = digitalRead(ldrPin);

  // If the digital value is HIGH, it indicates low light (dark)
  if (lightValue == HIGH) {
    digitalWrite(relayPin, HIGH); // Turn on the relay/bulb
  } else {
    digitalWrite(relayPin, LOW); // Turn off the relay/bulb
  }
  
  delay(100); // Adjust delay as needed
}
