// #include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// WiFi settings
const char* ssid = "project";
const char* password = "project@123";

// MQTT Broker Settings
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttClientId = "NodeMCU";
const char* mqttTopic = "temp_123";

// DHT settings
#define DHTPIN D4  // Replace with the GPIO pin you connected the DHT sensor to
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle incoming MQTT messages if needed
}

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Setup MQTT client
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(callback);

  // Connect to MQTT broker
  while (!mqttClient.connected()) {
    if (mqttClient.connect(mqttClientId)) {
      Serial.println("Connected to MQTT broker");
    } else {
      Serial.print("Failed to connect to MQTT broker. Reason: ");
      Serial.println(mqttClient.state());
      delay(5000);
    }
  }

  // Setup DHT sensor
  dht.begin();

  delay(3000);
}

void loop() {
  // Reconnect to MQTT broker if necessary
  if (!mqttClient.connected()) {
    while (!mqttClient.connected()) {
      if (mqttClient.connect(mqttClientId)) {
        Serial.println("Reconnected to MQTT broker");
      } else {
        Serial.print("Failed to reconnect to MQTT broker. Retrying in 5 seconds...");
        delay(5000);
      }
    }
  }

  // Read temperature from DHT sensor
  float temperature = dht.readTemperature();

  // Check if temperature reading is valid
  if (!isnan(temperature)) {
    // Convert temperature to String
    String temperatureString = String(temperature, 2);

    // Publish temperature to MQTT topic
    mqttClient.publish(mqttTopic, temperatureString.c_str());

    Serial.println("Published to MQTT: " + temperatureString);
  } else {
    Serial.println("Failed to read temperature from DHT sensor!");
  }

  // Maintain MQTT connection
  mqttClient.loop();
  delay(15000);  // Adjust the delay based on your requirements
}