// #include <WiFi.h>
// #include <PubSubClient.h>
// #include "DHTesp.h"

// DHTesp dht;
// const int dhtPin = 17;

// const char* ssid = "";
// const char* password = "";

// const char* mqttServer = "";
// const int mqttPort = 1883;

// const int soundSensorPin = 34;
// const float bias = 1.65;
// const float Vref = 0.00631;

// WiFiClient wifiClient;
// PubSubClient client(wifiClient);

// void handleReceivedCommand(String payload) {
//   if (payload.equals("Sound")) {
//     analogReadResolution(12);
//     analogSetAttenuation(ADC_11db);

//     const int numSamples = 1000;
//     float sumSquares = 0.0;

//     for (int i = 0; i < numSamples; i++) {
//       int sensorValue = analogRead(soundSensorPin);
//       float voltage = sensorValue * (3.3 / 4095.0);
//       float amplitude = voltage - bias;
//       sumSquares += amplitude * amplitude;
//       delayMicroseconds(100);
//     }

//     float rms = sqrt(sumSquares / numSamples);
//     float dB = 20 * log10(rms / Vref);

//     String noiseMsg = "Noise Level: " + String(dB, 2) + " db";
//     Serial.println(noiseMsg);
//     client.publish("mpcaProj/response", noiseMsg.c_str());
//     Serial2.println(noiseMsg); // Send to Arduino
//   } 
//   else if (payload.equals("Temperature")) {
//     TempAndHumidity data = dht.getTempAndHumidity();
//     if (dht.getStatus() != 0) {
//       String errorMsg = "DHT11 error: " + String(dht.getStatusString());
//       Serial.println(errorMsg);
//       client.publish("mpcaProj/response", errorMsg.c_str());
//       Serial2.println(errorMsg); // Send to Arduino
//     } else {
//       String tempMsg = "Temperature: " + String(data.temperature, 2) + " °C";
//       Serial.println(tempMsg);
//       client.publish("mpcaProj/response", tempMsg.c_str());
//       Serial2.println(tempMsg); // Send to Arduino
//     }
//   }
//   else if (payload.equals("Humidity")) {
//     TempAndHumidity data = dht.getTempAndHumidity();
//     if (dht.getStatus() != 0) {
//       String errorMsg = "DHT11 error: " + String(dht.getStatusString());
//       Serial.println(errorMsg);
//       client.publish("mpcaProj/response", errorMsg.c_str());
//       Serial2.println(errorMsg);
//     } else {
//       String humidityMsg = "Humidity: " + String(data.humidity, 2) + " %";
//       Serial.println(humidityMsg);
//       client.publish("mpcaProj/response", humidityMsg.c_str());
//       Serial2.println(humidityMsg);
//     }
//   }
//   else {
//     Serial.println("Unknown Command");
//     client.publish("mpcaProj/response", "Unknown Command");
//     Serial2.println("Unknown Command");
//   }
// }

// void callback(char* topic, byte* payload, unsigned int length) {
//   Serial.print("Message received on topic: ");
//   Serial.print(topic);
//   Serial.print(" with payload: ");
//   String payloadStr = "";

//   for (unsigned int i = 0; i < length; i++) {
//     payloadStr += (char)payload[i];
//     Serial.print((char)payload[i]);
//   }
//   Serial.println();
  
//   handleReceivedCommand(payloadStr);
// }

// void setup() {
//   Serial.begin(115200);
//   Serial2.begin(9600, SERIAL_8N1, 16, 17);  // ESP32 TX (17) -> Uno RX (10), ESP32 RX (16) <- Uno TX (11)

//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");
//   Serial.print("ESP32 IP Address: ");
//   Serial.println(WiFi.localIP());

//   dht.setup(dhtPin, DHTesp::DHT11);

//   client.setServer(mqttServer, mqttPort);
//   client.setCallback(callback);
// }

// void loop() {
//   if (!client.connected()) {
//     while (!client.connected()) {
//       Serial.println("Connecting to MQTT...");
//       if (client.connect("ESP32Client")) {
//         Serial.println("Connected to MQTT broker");
//         client.subscribe("mpcaProj/comm");
//       } else {
//         Serial.print("Failed to connect to MQTT, error code: ");
//         Serial.println(client.state());
//         delay(5000);
//       }
//     }
//   }

//   if (Serial2.available()) {
//     String message = Serial2.readStringUntil('\n');
//     Serial.print("Received from Arduino: ");
//     Serial.println(message);
//     client.publish("mpcaProj/response", message.c_str());
//   }

//   client.loop();
// }







// // Debugging


// void setup() {
//   Serial.begin(9600);  // Debug output
//   Serial2.begin(9600, SERIAL_8N1, 16, 17);  // Use pins 16 (RX) and 17 (TX)
  
//   Serial.println("ESP32 started");
// }

// void loop() {
//   if (Serial2.available()) {
//     String message = Serial2.readStringUntil('\n');
//     Serial.print("Received from Arduino: ");
//     Serial.println(message);
//   }
// }



void setup() {
  Serial.begin(9600);  // Debug output
  // Using Serial2 on pins 16 (RX) and 17 (TX) at 4800 baud
  Serial2.begin(4800, SERIAL_8N1, 16, 17);
  Serial.println("ESP32 started");
}

void loop() {
  // Send data to Arduino every 3 seconds
  String data = "Data from ESP32: " + String(millis());
  Serial2.println(data);
  Serial.println("Sent to Arduino: " + data);
  delay(3000);
}

