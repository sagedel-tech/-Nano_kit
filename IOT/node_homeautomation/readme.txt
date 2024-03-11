To run and perform the program provided, which is a simple web server setup for controlling a relay (for home automation purposes), follow these steps:

1. Hardware Setup:
   - Connect your NodeMCU board to the relay module. Ensure that the relay module's control pin is connected to pin D1 (or any other pin you prefer, just make sure to update the `relayPin` variable accordingly in the code).

2. Configure Wi-Fi Credentials:
   - Modify the `ssid` and `password` variables in the code to match your Wi-Fi network credentials.

3. Upload the Code:
   - Open the Arduino IDE.
   - Copy and paste the provided code into a new sketch in the Arduino IDE.
   - Connect your NodeMCU board to your computer using a USB cable.
   - Select the appropriate board (NodeMCU 1.0) and COM port from the `Tools` menu in the Arduino IDE.
   - Click the "Upload" button (arrow icon) or press `Ctrl + U` to compile and upload the code to your NodeMCU board.

4. Monitor Serial Output (Optional):
   - Open the Serial Monitor in the Arduino IDE (`Ctrl + Shift + M` or `Tools` > `Serial Monitor`) to monitor the serial output.
   - This will provide information about the Wi-Fi connection status and the IP address assigned to the NodeMCU board.

5. Access Web Interface:
   - Once the code is uploaded and the NodeMCU board is connected to your Wi-Fi network, it will start hosting a web server.
   - Open a web browser on any device connected to the same Wi-Fi network.
   - Enter the IP address of the NodeMCU board in the address bar of the web browser. You can find the IP address printed in the Serial Monitor.
   - You should see a simple web page with a button to toggle the relay state (turn on or off).

6. Control Relay:
   - Click the button on the web page to toggle the relay state.
   - The relay will switch between on and off states accordingly.
   - The web page will update to reflect the current state of the relay (On or Off).

7. Test and Debug:
   - Test the functionality thoroughly to ensure that the relay responds as expected.
   - Monitor the Serial Monitor for any debug information or errors that may occur during operation.

8. Modify and Customize (Optional):
   - You can modify the HTML code in the `handleRoot()` function to customize the appearance of the web interface.
   - Additionally, you can add more features or functionality to the web server as needed.


