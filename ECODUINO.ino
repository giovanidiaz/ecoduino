#include <dht11.h>
dht11 DHT;
#define MOISTURE_PIN A2  // soil Moisture sensor/
#define DHT11_PIN    9   // DHT11

float airHumidity;      // environment humidity
float airTemperature;   // environment temperature
float soilHumidity;       // soil moisture
float waterTemp;        // water temperature


int setHumidity = 50;      //Set the pump trigger threshold
boolean auto_irri = false;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  setup_pump();
}


void loop() {
  int chk;
  auto_irrigation();
  char data;

  if (Serial1.available() > 0) {
    data = Serial1.read();
    Serial.println(data);
  }

  if (Serial.available() > 0) {
    data     = Serial.read();
    //Serial.println(data);
  }
  //
  switch (data) {
    case 'A':                                  // A Temperatura del AGUA
      waterTemp = get_water_temp();
      Serial.println(waterTemp);
      Serial1.println(waterTemp);
      break;
    case 'B':                                  // B Humedad del Suelo
      soilHumidity = get_soil_humidity();
      Serial.println(soilHumidity);
      Serial1.println(soilHumidity);
      break;
    case 'C': 
      chk = DHT.read(DHT11_PIN);
      airHumidity = DHT.humidity;
      Serial.println(airHumidity);
      Serial1.println(airHumidity);
      airTemperature = DHT.temperature;
      Serial.println(airTemperature);
      Serial1.println(airTemperature);
      break;
    case 'D':                                 // D Humedad ambiental
      chk = DHT.read(DHT11_PIN);
      airHumidity = DHT.humidity;
      Serial.println(airHumidity);
      Serial1.println(airHumidity);
      break;
    case 'E':                                 // E Temperatura Ambiental
      chk = DHT.read(DHT11_PIN);
      airTemperature = DHT.temperature;
      Serial.println(airTemperature);
      Serial1.println(airTemperature);
      break;
    case 'F':
      Serial.println("TURN ON PUMP");
      pumpOn();
      break;
    case 'G':
      Serial.println("TURN OFF PUMP");
      pumpOff();
      auto_irri = false;
      break;
    case 'H':
      Serial.println("Enable Auto Irrigation");
      auto_irri = true;
      break;
    case 'I':
      Serial.println("Disable Auto Irrigation");
      auto_irri = false;
      pumpOff();
      break;
    case 'Z':                               // Z STOP DATA
     break;
  }

  delay(1000);
}
