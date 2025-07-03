# Wireless-Sensor-Network-Approach-to-Real-Time-Soil-Moisture-Analysis
A wireless soil moisture monitoring system using XBee enables real-time data transmission for precise irrigation. It reduces water waste, avoids over-irrigation, and improves crop health. The low-power, scalable design supports continuous monitoring, aiding smart, efficient agriculture.



This project develops a real-time soil moisture monitoring and automated irrigation system. It pairs FC‑28 capacitive soil moisture sensors with XBee S2C Pro modules and Arduino microcontrollers to continuously collect and transmit data wirelessly to a central base station, reducing manual intervention and optimizing irrigation schedules.

🔧 Key Objectives

    Enable real-time soil monitoring across wide areas.

    Automate irrigation by triggering water pumps based on moisture thresholds.

    Reduce water usage and promote sustainable agriculture.

    Design a low-power, scalable wireless sensor network using XBee module.
   

🧩 System Architecture

    Sensor Nodes:

        FC‑28 sensors measure soil moisture.

        DHT11 sensors track temperature and humidity.

        Arduino units process readings and engage water pump relays.

        XBee S2C Pro modules transfer data to the base station.

    Network Design:

        Star topology: multiple nodes send periodic telemetry to a central unit.

        Nodes transmit data every 2 seconds with low power consumption.

    Base Station:

        Receives and parses moisture, temperature, and humidity data.

        Displays soil condition (moist, over‑watery, dry) for informed irrigation decisions.

⚙️ Hardware Components

    Soil Moisture Sensor (FC‑28)

    XBee S2C Pro modules

    Arduino microcontroller

    Relay module for pump control

    DHT11 temperature & humidity sensor

    12 V Li‑Po battery (future solar integration possible)

    Tx
![cc_dd](https://github.com/user-attachments/assets/ea92ff43-b63e-4e6e-8bcd-7cc6061594bc)

Rx
![cc_dd_2](https://github.com/user-attachments/assets/5639898f-548c-46b5-8737-38a4ec7655d3)

🧠 Software & Firmware

    Firmware written in Embedded C via Arduino IDE.

    XBee modules configured using XCTU utility.

    Optional Python scripts for data logging and visualization.
    
🧪 Testing & Results

    Range reliability: Stable XBee communication up to 200 m with minimal data loss.

    Accuracy: Sensor readings of humidity (~43%), temperature (~31 °C), and soil moisture (values between 309–972) reached receiver unchanged.

    Responsiveness: Data updated every 2 s with no noticeable delays.

    Energy use: Low-power consumption noted; further optimization planned.

    Water efficiency: Pump activation is automated, reducing wastage and human effort.

✅ Outcomes & Benefits

    Autonomous soil moisture monitoring and irrigation.

    Improved water management and crop yield.

    Scalable framework suitable for fields and greenhouses.

    Potential to integrate solar power, cloud storage, and ML-based irrigation forecasting.

⚙️ Future Enhancements

    Analyze system power consumption and integrate solar/energy harvesting.

    Add cloud connectivity for remote access and trend analytics.

    Use machine learning to optimize irrigation schedules and predictive insights 
