1) Install Arduino IDE:

    -Download and install the Arduino IDE from the official website: Arduino Software.
    -Ensure you have the latest version installed, as older versions might lack support for the NodeMCU board.

2) Add ESP8266 Board Manager:

    -Open Arduino IDE.
    -Go to File > Preferences.
    -In the "Additional Board Manager URLs" field, add the following URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json.
    -Click "OK" to close the Preferences window.

3) Install ESP8266 Board Package:

    -Go to Tools > Board > Boards Manager....
    -Type "esp8266" in the search bar.
    -Select the "esp8266" platform by ESP8266 Community and click "Install".
    -Once installed, close the Boards Manager window.

4) Select NodeMCU Board:

    -Now that the ESP8266 board package is installed, you can select the NodeMCU board.
    -Go to Tools > Board and choose "NodeMCU 1.0 (ESP-12E Module)" from the list.

5) Select Port:

    -Connect your NodeMCU board to your computer using a USB cable.
    -Go to Tools > Port and select the port that corresponds to your NodeMCU board.

6) Verify Installation:

    -To ensure that everything is set up correctly, upload a simple example sketch to your NodeMCU board.
    -Go to File > Examples > ESP8266 > Blink.
    -This will open the Blink sketch, which blinks an LED connected to pin D4 on the NodeMCU board.
    -Click the "Upload" button (arrow icon) or press Ctrl + U to compile and upload the sketch to your NodeMCU board.
    -If everything is set up correctly, you should see the built-in LED on your NodeMCU board blinking.
