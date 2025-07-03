#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);  // XBee: RX → D2, TX → D3

void setup() {
    Serial.begin(9600);  // Serial Monitor
    xbee.begin(9600);    // XBee Communication
}

void loop() {
    if (xbee.available()) {
        String receivedData = xbee.readStringUntil('\n'); // Read incoming data until newline
        receivedData.trim(); // Remove any leading/trailing spaces or newlines

        Serial.print("Received Data: ");
        Serial.println(receivedData);

        // Split the received data (format: Moisture,Status,Temperature,Humidity)
        int firstComma = receivedData.indexOf(',');
        int secondComma = receivedData.indexOf(',', firstComma + 1);
        int thirdComma = receivedData.indexOf(',', secondComma + 1);

        if (firstComma > 0 && secondComma > firstComma && thirdComma > secondComma) {
            String moisture = receivedData.substring(0, firstComma);
            String status = receivedData.substring(firstComma + 1, secondComma);
            String temperature = receivedData.substring(secondComma + 1, thirdComma);
            String humidity = receivedData.substring(thirdComma + 1);

            Serial.print("Soil Moisture: "); Serial.println(moisture);
            Serial.print("Moisture Status: "); Serial.println(status);
            Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
            Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
        } else {
            Serial.println("Error: Incorrect data format received!");
        }
    }
}
