
### Hardware Required:
1. Arduino board
2. DHT11 temperature and humidity sensor
3. Ultrasonic sensor (HC-SR04 or similar)
4. Servo motor
5. L298N motor driver
6. 16x2 I2C LCD display
7. Connecting wires

### Connections:
1. Connect the DHT11 sensor to digital pin 2 of the Arduino board.
2. Connect the ultrasonic sensor trigger pin to analog pin A1 and echo pin to analog pin A2 of the Arduino board.
3. Connect the servo motor signal pin to digital pin 10 of the Arduino board.
4. Connect the L298N motor driver:
   - Left motor forward pin to digital pin 6
   - Left motor backward pin to digital pin 7
   - Right motor forward pin to digital pin 5
   - Right motor backward pin to digital pin 4
5. Connect the I2C pins of the LCD display to the corresponding SDA and SCL pins on the Arduino board.

### Procedure:
1. Install the necessary libraries:
   - LiquidCrystal_I2C library for the LCD display.
   - DHT library for the DHT11 sensor.
   - Servo library for controlling the servo motor.
   - NewPing library for the ultrasonic sensor.
2. Upload the combined code to the Arduino board.
3. Open the serial monitor to view temperature and humidity readings from the DHT11 sensor.
4. The LCD will display the temperature and humidity readings.
5. The ultrasonic sensor will continuously measure distances.
6. If an obstacle is detected within 20 cm, the robot will stop, move backward, and then turn either left or right based on the obstacle's position.
7. The servo motor will rotate left and right to scan for obstacles.
8. Adjust the code as needed for your specific hardware setup, such as pin assignments and sensor orientations.
9. Power the Arduino board using an appropriate power source.


