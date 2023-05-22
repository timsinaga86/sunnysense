
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

  WiFiClient w;

  PubSubClient client("iotce365.azure-devices.net", 8883, w);

  Serial.print("Connecting to Azure IoT through MQTT.");
  while (!mqttStatus) {
    mqttStatus = client.connect(
      "sunnysense",
      "iotce365.azure-devices.net/sunnysense/?api-version=2020-09-30",
      "SharedAccessSignature sr=iotce365.azure-devices.net%2Fdevices%2Fsunnysense&sig=mFPGn3K1nXluQNmFmh4R5%2F4i9YIegU%2F96oF93VvEut0%3D&se=1685384273");
      Serial.print(" .");
    delay(3000);
  }
  Serial.println("\nConnected to Azure!");
}

void loop() {
  // // scan for existing networks:
  // Serial.println("Scanning available networks...");
  // listNetworks();
  delay(10000);
}