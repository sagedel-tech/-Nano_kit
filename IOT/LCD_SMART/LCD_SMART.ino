#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Wire.h> // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library 

// Set the LCD address to 0x27 for a 16x2 display (adjust accordingly if different)
LiquidCrystal_I2C lcd(0x27, 16, 2);

AsyncWebServer server(80);

const char* ssid = "realme X3";  //wifi ssid
const char* password = "12345678";   //wifi password

const char* PARAM_INPUT_1 = "input1";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Smart Notice Board</title>
  <meta name="viewport" content="width=device-width, initial-scale=5">
<p> <font size="9" face="sans-serif"> <marquee> Smart Notice Board </marquee> </font> </p>
  </head><body><center>
  <form action="/get">
    Enter Text to Display: <input type="text" name="input1">
    <input type="submit" value="Send">
  </form><br>
 
</center></body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(D2, D1); // Initialize the I2C communication (SDA pin to D2, SCL pin to D1)
  lcd.init(); // Initialize the LCD

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME");

  // Turn on the backlight (full brightness)
  lcd.backlight();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed!");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String message;
    String inputParam;
    if (request->hasParam(PARAM_INPUT_1)) {
      message = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(message);
    }
    else {
      message = "No message sent";
      inputParam = "none";
    }
    Serial.println(message);
    request->send(200, "text/html", index_html);
  });

  server.onNotFound(notFound);
  server.begin();
}

void loop() {
  // Nothing to do here, since we don't want the text to move
  delay(1000); // Add a delay to avoid unnecessary CPU usage
}
