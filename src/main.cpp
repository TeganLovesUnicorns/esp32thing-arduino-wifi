#include <Arduino.h>
#include <WiFi.h>
#include <EEPROM.h> // even though the ESP32 technically uses Flash and not EEPROM.

// Web Server should have IP of 192.168.4.1

// Home Network Creds - eventually pulled from mem via EEPROM.h
const char* ssid = "";
const char* password = "";

void initWiFi(){
  Serial.print("connecting to: ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  int timeout = 10 * 4; // 10 seconds  
  while (WiFi.status() != WL_CONNECTED && (timeout-- > 0)){
    delay(250);
    Serial.print(".");
  }

  Serial.println("");

  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect, going back to sleep");
  }

  Serial.print("WiFi connected in: ");
  Serial.print(millis());
  Serial.print(", IP Address: ");
  Serial.println(WiFi.localIP());
}


void initAP(){
  // AP Network Credentials
  const char* ap_ssid = "ESP32-Thing";
  const char* ap_password = "testing1234";
 
  // Set web server to port 80
  WiFiServer server(80);

  // Variable to store the HTTP Request
  String header;

  // Aux Variables to store new SSID and Password
  String new_ssid = "";
  String new_pword = "";

}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}