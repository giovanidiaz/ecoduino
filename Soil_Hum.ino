


int get_soil_humidity() {

  return soilHumidity = map(analogRead(MOISTURE_PIN), 0, 1023, 0, 100);    //Map analog value to 0~100% soil moisture value

}
