#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "realme X3";
const char* password = "12345678";

const int relayPin = D1; // Relay control pin
bool relayState = LOW; // Initial state of the relay (LOW = off, HIGH = on)

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
  String html = "<html><head><title>Home Automation</title></head><body>";
  html += "<h1>Home Automation</h1>";
  html += "<p>LED Status: ";
  html += (relayState == HIGH) ? "On" : "Off";
  html += "</p>";
  html += "<form action='/toggle' method='get'>";
  html += "<button type='submit'>";
  html += (relayState == HIGH) ? "Turn Off" : "Turn On";
  html += "</button>";
  html += "</form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleToggle() {
  relayState = !relayState; // Toggle relay state
  digitalWrite(relayPin, relayState);
  server.sendHeader("Location", "/");
  server.send(303); // Redirect to the root page after toggling
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, relayState); // Set initial relay state
  
  setupWiFi();

  server.on("/", HTTP_GET, handleRoot);
  server.on("/toggle", HTTP_GET, handleToggle);
  
  server.begin();
}

void loop() {
  server.handleClient();
}
