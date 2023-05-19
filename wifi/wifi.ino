#include <PubSubClient.h>

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
bool mqttStatus = false;
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

  while (status != WL_CONNECTED) {
    Serial.printf("Connecting to network %s\n", ssid);
    WiFi.begin(ssid);
    delay(10000);
    status = WiFi.status();
    Serial.printf("Status: %d\n", status);
  }

  Serial.printf("Connected to network %s\n", ssid);

  PubSubClient client;

  Serial.println("Connecting to Azure IoT through MQTT.");
  while (!mqttStatus) {
    mqttStatus = client.connect(
      "sunnysense",
      "iotce365.azure-devices.net/sunnysense/?api-version=2021-04-12",
      "HostName=iotce365.azure-devices.net;DeviceId=sunnysense;SharedAccessSignature=SharedAccessSignature sr=iotce365.azure-devices.net%2Fdevices%2Fsunnysense&sig=nYOeO9wHq6HMkfz%2Fc9M42qqy%2B3jaCA7RGqeK%2FfqPtNE%3D&se=1744462307"
      );
      delay(3000);
  }
  Serial.println("Connected to Azure!");
}

void loop() {
  // // scan for existing networks:
  // Serial.println("Scanning available networks...");
  // listNetworks();
  delay(10000);
}