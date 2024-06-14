#include <MQ135.h>

const int sensorPin = A0; 
const int ledPin = 13;    

const int threshold = 200; 

MQ135 gasSensor = MQ135(A0);

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float gasResistance = gasSensor.getResistance(voltage);

  float airQuality = gasSensor.getCorrectedPPM();

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.print("Gas Resistance: ");
  Serial.println(gasResistance);
  Serial.print("Air Quality: ");
  Serial.println(airQuality);

  if (airQuality > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
