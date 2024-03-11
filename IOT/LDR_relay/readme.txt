To run and perform the given program using an LDR (Light Dependent Resistor) sensor and a relay connected to a NodeMCU controller, follow these steps:

1. Hardware Setup:
   - Connect the LDR sensor module to digital pin D6 (NodeMCU GPIO 6).
   - Connect the relay control pin to digital pin D3 (NodeMCU GPIO 3).
   - Ensure proper wiring and connections according to the pin configurations in the code.

2. Upload Code:
   - Open the Arduino IDE.
   - Copy the provided code and paste it into a new sketch window in the Arduino IDE.

3. Verify and Compile:
   - Click on the verify button (checkmark icon) or press `Ctrl + R` to verify the code for any syntax errors.
   - Fix any errors if encountered.

4. Select Board and Port:
   - Go to `Tools` > `Board` and select "NodeMCU 1.0 (ESP-12E Module)".
   - Go to `Tools` > `Port` and select the appropriate port connected to your NodeMCU board.

5. Upload Code:
   - Click on the upload button (right arrow icon) or press `Ctrl + U` to upload the code to your NodeMCU board.
   - Monitor the upload process in the status bar.

6. Monitor Output:
   - Once the code is uploaded successfully, open the Serial Monitor (`Ctrl + Shift + M`) to observe the output.
   - The program does not output any data to the Serial Monitor, but you can use it for debugging if needed.

7. Operation:
   - The program continuously reads the LDR sensor's digital value.
   - If the digital value is `HIGH`, indicating low light (dark), the relay pin is set to `HIGH` to turn on the relay/bulb.
   - If the digital value is `LOW`, indicating sufficient light, the relay pin is set to `LOW` to turn off the relay/bulb.
   - Ensure proper lighting conditions to test the functionality.
   - Adjust the delay as needed in the `loop()` function to control the responsiveness of the system.

8. Testing:
   - Test the setup by adjusting the lighting conditions around the LDR sensor.
   - Verify that the relay switches on when the light is low and switches off when the light is sufficient.

9. Troubleshooting:
   - If the system does not function as expected, double-check the wiring and connections.
   - Ensure that the NodeMCU board is powered properly and connected to the correct port.
   - Check for any error messages in the Arduino IDE's output window.

