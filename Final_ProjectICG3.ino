#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <MQ135.h>

// Pin definitons
#define DHTPIN 13      // Pin where the DHT11 is connected
#define DHTTYPE DHT11 // Define the type of DHT sensor
#define MQ135PIN 15   // Pin where the MQ135 is connected

DHT dht(DHTPIN, DHTTYPE);
MQ135 mq135_sensor(MQ135PIN);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // Read temperature and humidity from DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari sensor DHT!");
    return;
  }

  // Read gas concentration from MQ135
  float mq135_value = mq135_sensor.getPPM();

  // Output the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Air Quality (PPM): ");
  Serial.print(mq135_value);
  Serial.println();

  // Check for fire conditions
  if (t > 50 || mq135_value > 300) {
    Serial.println("Api Terdeteksi!");
    // Add additional code here to handle fire detection, like sending alerts
  }

  delay(2000); // Wait a few seconds between measurements
}