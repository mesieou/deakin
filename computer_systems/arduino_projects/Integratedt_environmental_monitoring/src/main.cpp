#include "DHT.h"

// --- Pin Definitions ---
#define DHTPIN 2          // Digital pin connected to the DHT22
#define DHTTYPE DHT22     // DHT 22 (AM2302)
#define MOISTURE_PIN A0   // Analog pin for Soil Moisture sensor

#define GREEN_LED 5       // Pin for green LED
#define RED_LED 6         // Pin for red LED

// --- Thresholds ---
#define TEMP_THRESHOLD 30.0       // Celsius
#define HUMIDITY_THRESHOLD 60.0   // Percent
#define MOISTURE_THRESHOLD 700    // Analog value (0–1023)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(MOISTURE_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, HIGH);  // Green LED always ON
}

void loop() {
  // --- Read temperature and humidity ---
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // --- Read soil moisture ---
  int moistureLevel = analogRead(MOISTURE_PIN);

  // --- Output to Serial Monitor ---
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Soil Moisture: ");
  Serial.println(moistureLevel);

  // --- Check if any reading failed ---
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // --- Logic for Red LED ---
  if (temperature > TEMP_THRESHOLD && humidity > HUMIDITY_THRESHOLD && moistureLevel > MOISTURE_THRESHOLD) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
  }

  delay(2000);  // Wait for 2 seconds before the next reading
}
