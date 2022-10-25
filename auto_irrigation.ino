


void auto_irrigation() {
  if (auto_irri == true) {
    
    int soilHum = get_soil_humidity();
    Serial.print("soilHum: ");
    Serial.println(soilHum);
    Serial.print("setHumidity: ");
    Serial.println(setHumidity);
    if (soilHum < setHumidity) {
      Serial.println("Humedad baja Activando Bomba");
      pumpOn();
    } else {
      Serial.println("Humedad alta Apagando Bomba");
      pumpOff();
    }
  }
}
