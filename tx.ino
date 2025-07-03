#include <SoftwareSerial.h>
#include <DHT.h>

// Pin Definitions
#define MOISTURE_SENSOR A0  // Soil Moisture Sensor
#define DHTPIN 6            // DHT11 Sensor connected to D6
#define DHTTYPE DHT11       // DHT11 Sensor Type

SoftwareSerial xbee(2, 3);  // XBee: RX → D2, TX → D3
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT11 Sensor

void setup() {
    Serial.begin(9600);
    xbee.begin(9600);  // XBee communication baud rate
    dht.begin();
    pinMode(MOISTURE_SENSOR, INPUT);
}

void loop() {
    int moistureValue = analogRead(MOISTURE_SENSOR);  // Read soil moisture
    float temperature = dht.readTemperature();  // Read temperature (Celsius)
    float humidity = dht.readHumidity();        // Read humidity

    // Check if DHT11 readings are valid
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT11 sensor!");
        return;
    }

    // Determine soil moisture status
    String moistureStatus;
    if (moistureValue < 400) {
        moistureStatus = "Wet";
    } else if (moistureValue >= 400 && moistureValue <= 800) {
        moistureStatus = "Moist";
    } else {
        moistureStatus = "Dry";
    }

    // Print data to Serial Monitor
    Serial.print("Soil Moisture: "); Serial.print(moistureValue);
    Serial.print(" ("); Serial.print(moistureStatus); Serial.println(")");
    Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");

    // Send data via XBee
    xbee.print(moistureValue);
    xbee.print(",");
    xbee.print(moistureStatus);
    xbee.print(",");
    xbee.print(temperature);
    xbee.print(",");
    xbee.print(humidity);
    xbee.print("\n");  // Send newline for readability

    delay(1000);  // Delay for stability
}
