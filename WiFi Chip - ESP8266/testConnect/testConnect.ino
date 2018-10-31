#include <ESP8266WiFi.h>

void setup() {
    Serial.begin(115200);
    Serial.println();    
    // Connect to preset Eduardo Network
   
    WiFi.begin("Eduardo", "dosdequesoconloroco");

    Serial.print("Connecting");
    // Animate Connection
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
      }
    Serial.println();

    Serial.print("Connected with IP address: ");
    Serial.print(WiFi.localIP());
  }
void loop() {}

