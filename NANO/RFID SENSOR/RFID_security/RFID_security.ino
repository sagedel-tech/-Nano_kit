#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 6
#define GREEN_LED 3 // Connect the green LED to digital pin 7
#define RED_LED 2   // Connect the red LED to digital pin 8

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo servo;

bool doorLocked = true;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  servo.attach(SERVO_PIN);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  lockDoor();
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Card Detected!");

    if (checkCardAuthorization()) {
      Serial.println("Access Granted");
      digitalWrite(GREEN_LED, HIGH); // Turn on the green LED
      //delay(2000); // Keep the LED on for 1 second
      unlockDoor();
      digitalWrite(GREEN_LED, LOW); // Turn off the green LED
      delay(2000); // Keep the door unlocked for 5 seconds
      lockDoor();

    } else {
      Serial.println("Access Denied");
      digitalWrite(RED_LED, HIGH); // Turn on the red LED
      delay(1000); // Keep the LED on for 1 second
      digitalWrite(RED_LED, LOW); // Turn off the red LED
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}

bool checkCardAuthorization() {
  byte authorizedCardUID[] = {0x01, 0x9C, 0x0f, 0x26}; // remove 01, 9C, 0f, 26 and replace with your value

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] != authorizedCardUID[i]) {
      return false;
    }
  }
  return true;
}


void unlockDoor() {
  if (doorLocked) {
    Serial.println("Unlocking the door!");
    servo.write(0);
    delay(500);
    doorLocked = false;
  }
}

void lockDoor() {
  if (!doorLocked) {
    Serial.println("Locking the door!");
    servo.write(90);
    delay(500);
    doorLocked = true;
  }
}
