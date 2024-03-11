// Define pins for ultrasonic sensor
const int trigPin = 9; // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor

// Define pins for LEDs
const int greenLEDPin = 2; // Pin for green LED
const int yellowLEDPin = 3; // Pin for yellow LED
const int redLEDPin = 4; // Pin for red LED

// Variables to store the distance measured and trash bin value
long duration;
int distance;


void setup() {
  // Set up ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  

  
  // Set up LED pins
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Activate the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert duration to distance

  
  // Print the distance and trash bin value
  Serial.print("Distance: ");
  Serial.println(distance);

  // Control the LEDs based on the distance
  if (distance <= 2) {
    // If the distance is less than or equal to 10 cm, turn on the red LED
    digitalWrite(greenLEDPin, LOW); // Turn off green LED
    digitalWrite(yellowLEDPin, LOW); // Turn off yellow LED
    digitalWrite(redLEDPin, HIGH); // Turn on red LED
  } else if (distance <= 5) {
    // If the distance is between 10 cm and 20 cm, turn on the yellow LED
    digitalWrite(greenLEDPin, LOW); // Turn off green LED
    digitalWrite(yellowLEDPin, HIGH); // Turn on yellow LED
    digitalWrite(redLEDPin, LOW); // Turn off red LED
  } else {
    // If the distance is greater than 20 cm, turn on the green LED
    digitalWrite(greenLEDPin, HIGH); // Turn on green LED
    digitalWrite(yellowLEDPin, LOW); // Turn off yellow LED
    digitalWrite(redLEDPin, LOW); // Turn off red LED
  }
  
  // Add a delay before the next reading
  delay(500); // Wait for half a second
}
