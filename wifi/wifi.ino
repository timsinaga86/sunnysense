#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

char ssid[] = "Device-Northwestern";   
int status = WL_IDLE_STATUS;
byte mac[6];

void setup() {
  Serial.begin(9600);
  Serial.println();
  delay(2000);

  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());

  // WiFi.macAddress(mac);
  // delay(5000);
  // printMac();

  WiFi.mode(WIFI_STA);

  while(status != WL_CONNECTED){
    Serial.printf("Connecting to network %s\n", ssid);
    WiFi.begin(ssid);
    delay(10000);
    status = WiFi.status();
    Serial.printf("Status: %d\n", status);
  }

  Serial.printf("Connected to network %s\n", ssid);
}

void loop() {
  // // scan for existing networks:
  // Serial.println("Scanning available networks...");
  // listNetworks();
  delay(10000);
}