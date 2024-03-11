const int touchSensorPin = 2;  // Touch sensor connected to digital pin 2
const int relayPin = 3;        // Relay control pin connected to digital pin 3

void setup() {
  pinMode(touchSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure relay is initially off
  Serial.begin(9600);
}

void loop() {
  // Read the state of the touch sensor
  int touchState = digitalRead(touchSensorPin);

  // If touch is detected, turn on the relay
  if (touchState == HIGH) {
    digitalWrite(relayPin, HIGH); // Turn on the relay
    Serial.println("Touch detected: Relay turned on");
  } else {
    digitalWrite(relayPin, LOW); // Turn off the relay
  }
  
  delay(100); // Adjust delay as needed
}
