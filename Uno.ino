// #include <SoftwareSerial.h>

// // Define software serial pins
// SoftwareSerial espSerial(10, 11);  // RX = 10, TX = 11

// void setup() {
//   Serial.begin(115200);      // Hardware Serial for debugging
//   espSerial.begin(9600);     // Software Serial for ESP32 communication
  
//   Serial.println("Arduino Uno started");
//   Serial.println("Waiting for ESP32 response...");

//   // Notify ESP32 that Uno is connected
//   espSerial.println("UNO_CONNECTED");
// }

// void loop() {
//   // Check if data is received from ESP32
//   if (espSerial.available()) {
//     String message = espSerial.readStringUntil('\n');
//     Serial.print("Message from ESP32: ");
//     Serial.println(message);
//   }

//   // Send some example data to ESP32 every 3 seconds
//   delay(3000);
  
//   String data = "Arduino Data: " + String(random(0, 100));  // Simulating sensor data
//   espSerial.println(data);
//   Serial.println("Sent to ESP32: " + data);
// }





//  // Debugging

// // Uno to esp works

// #include <SoftwareSerial.h>

// // Using pins 10 (RX) and 11 (TX) for communication with ESP32
// SoftwareSerial espSerial(0,1);  

// void setup() {
//   Serial.begin(9600);      // Debug output
//   espSerial.begin(9600);     // Communication with ESP32
  
//   Serial.println("Arduino Uno started");
//   delay(1000);
// }

// void loop() {
//   // Send a simple test message every 3 seconds
//   espSerial.println("Hello from Uno!");
//   Serial.println("Sent: Hello from Uno!");
//   delay(3000);
// }



// // ESP to uno not working
// // 3.3v to 5v issue

#include <SoftwareSerial.h>

// Use SoftwareSerial with pin 8 as RX and pin 11 as TX
SoftwareSerial espSerial(8, 11);  

void setup() {
  Serial.begin(9600);      // For debugging via Serial Monitor
  espSerial.begin(4800);   // Must match ESP32 baud rate (4800)
  Serial.println("Arduino Uno started");
}

void loop() {
  if (espSerial.available()) {
    String message = espSerial.readStringUntil('\n');
    Serial.print("Received from ESP32: ");
    Serial.println(message);
  }
  // Optionally, send data back if needed
}


