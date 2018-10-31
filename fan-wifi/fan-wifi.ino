/*
    HTTP over TLS (HTTPS) example sketch
    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp8266/Arduino project continuous integration
    build.
    Limitations:
      only RSA certificates
      no support of Perfect Forward Secrecy (PFS)
      TLSv1.2 is supported since version 2.4.0-rc1
    Created by Ivan Grokhotkov, 2015.
    This example is in public domain.
*/

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "Eduardo";
const char* password = "dosdequesoconloroco";

const char* host = "5mjz0sb5kk.execute-api.us-west-2.amazonaws.com/";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "54 F8 E6 75 3A 9C DB 50 9C B6 B0 0C AD 5A C4 3E 16 25 6D 32";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);/*
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  
  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }
  */
  String url = "/prod/";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection"); 
}

void loop() {
}
