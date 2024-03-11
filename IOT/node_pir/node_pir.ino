#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "realme X3";
const char* password = "12345678";
const char* serverAddress = "127.0.0.1"; // Localhost

const int pirPin = D1; // PIR sensor pin

ESP8266WebServer server(80);

void setupWiFi() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void handleRoot() {
  String html = "<html><head><title>Motion Detection</title></head><body>";
  html += "<h1>Motion Detection</h1>";
  html += "<p>Motion detected: ";
  
  if (motionDetected()) {
    html += "Yes</p>";
  } else {
    html += "No</p>";
  }
  
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

bool motionDetected() {
  return digitalRead(pirPin) == HIGH;
}

void setup() {
  pinMode(pirPin, INPUT);
  
  setupWiFi();

  server.on("/", HTTP_GET, handleRoot);
  
  server.begin();
}

void loop() {
  server.handleClient();
}
