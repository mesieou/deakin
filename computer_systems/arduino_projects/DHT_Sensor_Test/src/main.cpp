#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302)

// creates the sensor object
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    // allows to receive info from arduino
    Serial.begin(9600);
    Serial.println("Initializing sensor...");
    delay(2000);


    // initialises the sensor object
    dht.begin();
    Serial.println("Sensor initialized");
    delay(2000);

}

void loop() {
    Serial.println("Reading data...");  // Debugging print to check if loop is running
    
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Temp: ");
    Serial.print(temperature);
    Serial.println(" Celsius");

    delay(2000);  // Wait for 2 seconds
}
