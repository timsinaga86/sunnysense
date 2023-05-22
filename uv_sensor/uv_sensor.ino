#define UVPIN 36

uint32_t sensorMilliVolt;

void setup() 
{
  Serial.begin(9600);
}
 
void loop() 
{
  sensorMilliVolt = analogReadMilliVolts(UVPIN);
  Serial.printf("Sensor voltage: %d mV\n", sensorMilliVolt);
  Serial.printf("UV index: %d\n", sensorMilliVolt * 10 / 1000);
  Serial.printf("UV diode current: %f μA\n\n", (double) sensorMilliVolt / 1000 / 4.3);
  delay(2000);
}
