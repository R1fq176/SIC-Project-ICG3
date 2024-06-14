import random
import time

def read_sensor():
    sensor_value = random.randint(0, 1023)
    voltage = sensor_value * (5.0 / 1023.0)
    gas_resistance = random.uniform(10, 100)
    air_quality = random.uniform(0, 500) 

    return {
        "sensor_value": sensor_value,
        "voltage": voltage,
        "gas_resistance": gas_resistance,
        "air_quality": air_quality
    }

def control_led(sensor_data):
    threshold = 200  # Adjust threshold as needed
    if sensor_data["air_quality"] > threshold:
        print("Air quality above threshold. Turning on LED.")
    else:
        print("Air quality below threshold. Turning off LED.")
def main():
    while True:
        sensor_data = read_sensor()
        print("Sensor Data:", sensor_data)
        control_led(sensor_data)
        time.sleep(1) 

if __name__ == "__main__":
    main()
