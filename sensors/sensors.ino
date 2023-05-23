#include "DHT.h"

#define DHTPIN 15
#define UVPIN 36
#define DHTTYPE DHT22

uint32_t sensorMilliVolt;
float hif, hic;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // sensor is slow to update readings
  delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  } else {
    // Compute heat index in Fahrenheit (the default)
    hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    hic = dht.computeHeatIndex(t, h, false);
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
  }

  sensorMilliVolt = analogReadMilliVolts(UVPIN);
  // Serial.printf("Sensor voltage: %d mV\n", sensorMilliVolt);
  Serial.printf("UV index: %d\n", sensorMilliVolt * 10 / 1000);
  // Serial.printf("UV diode current: %f μA\n\n", (double) sensorMilliVolt / 1000 / 4.3);
  // delay(2000);
}
