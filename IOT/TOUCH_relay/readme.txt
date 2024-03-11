To run and perform the specified program using an Arduino board, follow these steps:

Hardware Setup:
1. Connect the touch sensor to digital pin 2 (touchSensorPin).
2. Connect the relay control pin to digital pin 3 (relayPin).

Software Setup:

1. Install Arduino IDE:
   - Download and install the Arduino IDE from the official website: [Arduino Software](https://www.arduino.cc/en/software).

2. Connect Arduino Board:
   - Connect your Arduino board to your computer using a USB cable.

3. Open Arduino IDE:
   - Open the Arduino IDE software.

4. Copy and Paste Code:
   - Copy the provided program code.
   - Paste the code into the Arduino IDE window.

5. Upload Code:
   - Click the "Upload" button (arrow icon) or press `Ctrl + U` to compile and upload the code to your Arduino board.
   - Monitor the upload process in the bottom status bar of the Arduino IDE.

6. Monitor Output:
   - Open the Serial Monitor by clicking `Tools` > `Serial Monitor` or pressing `Ctrl + Shift + M`.
   - Ensure the baud rate is set to 9600 (same as `Serial.begin(9600);` in the code).

### Running the Program:

1. Testing Touch Sensor:
   - Bring an object (such as a finger) close to the touch sensor.
   - Observe the Serial Monitor output; it should display "Touch detected: Relay turned on".
   - This indicates that the relay is activated when the touch sensor detects input.

2. Relay Control:
   - When the touch sensor is not triggered, the relay should remain off.
   - When the touch sensor is triggered (touched), the relay should activate.

3. Adjustments:
   - If needed, adjust the delay in the `loop()` function (`delay(100)`) to control the responsiveness of the system.
   - Longer delays may reduce sensitivity to rapid changes in touch sensor state, while shorter delays may increase responsiveness.

4. Further Testing:
   - Conduct further testing as necessary to ensure the system operates reliably and meets your requirements.

