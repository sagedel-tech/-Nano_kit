To run and perform the program using the provided code for the NodeMCU controller, follow these steps:

1. Setup Hardware Connections:
   - Connect the components according to the pin mappings defined in the code:
     - Motors connected to pins `enA`, `in1`, `in2`, `in3`, `in4`, and `enB`.
     - Infrared (IR) sensors connected to pins `L_S` (Left sensor) and `R_S` (Right sensor).
     - Ultrasonic sensor connected to pins `echo` (Echo pin) and `trigger` (Trigger pin).
     - Servo motor connected to the pin `servo`.

2. Install Arduino IDE and Configure:
   - Install the Arduino IDE if you haven't already.
   - Add the ESP8266 board manager and select the NodeMCU board as described in the previous procedure for NodeMCU.

3. Copy and Paste the Code:
   - Open the Arduino IDE.
   - Create a new sketch (File > New).
   - Copy the provided code and paste it into the Arduino IDE.

4. Verify and Upload the Code:
   - Verify the code for any errors by clicking the checkmark icon or selecting Sketch > Verify/Compile.
   - If there are no errors, upload the code to your NodeMCU board by clicking the upload button (arrow icon) or selecting Sketch > Upload.

5. Monitor Serial Output:
   - Open the serial monitor in the Arduino IDE (Tools > Serial Monitor) to observe the output messages from the NodeMCU.
   - The serial output will display the distances measured by the ultrasonic sensor and any other debugging information.

6. Interact with Sensors:
   - Place objects in front of the infrared sensors (Left and Right) to test their functionality.
   - Observe how the motor control responds to the sensor inputs.
   - Adjust the set distance value `Set` and other parameters as needed for your specific setup and requirements.

7. Test Servo Motor:
   - Observe the servo motor's movement during the initialization phase and when it adjusts its position based on the sensor readings.
   - Ensure that the servo motor rotates smoothly and accurately according to the provided code.

8. Experiment and Fine-Tuning:
   - Experiment with different configurations, sensor placements, and control logic to achieve the desired behavior.
   - Fine-tune the code parameters and thresholds to optimize the performance of your NodeMCU-controlled system.

9. Safety Precautions:
   - Exercise caution when testing the system, especially if it involves moving parts such as motors and servos.
   - Ensure that the environment is safe and free from obstacles to prevent collisions or damage.

