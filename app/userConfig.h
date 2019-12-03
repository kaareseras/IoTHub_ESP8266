//Edit this file to match your setup

// Physical device information for board and sensor
#define DEVICE_ID "test2"

//Change DHT type between DHT11 and DHT22
#define DHT_TYPE DHT11

// Pin layout configuration
#define LED_PIN 2
#define DHT_PIN 14

#define TEMPERATURE_ALERT 30

// Interval time(ms) for sending message to IoT Hub
#define INTERVAL 2000

// If don't have a physical DHT sensor, can send simulated data to IoT hub
#define SIMULATED_DATA true
