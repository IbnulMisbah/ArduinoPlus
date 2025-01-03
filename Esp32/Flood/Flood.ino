#include <WiFi.h>

// পিন ডেফিনেশন
const int rainSensorPin = 14;    // Rain sensor connected to GPIO 14
const int waterLevelPin = 34;    // Water level sensor connected to GPIO 34 (Analog pin)

// Wi-Fi credentials
const char* ssid = "Ismail-Al-Jazari";
const char* password = "hizbullah";

// সময়ের জন্য ভেরিয়েবল
unsigned long lastTime = 0;
unsigned long interval = 180000; // 3 minutes in milliseconds (3 minutes interval for water level rising)

void setup() {
  // Serial Monitor শুরু করুন
  Serial.begin(115200);
  
  // Rain sensor পিন ইনিশিয়ালাইজ করুন
  pinMode(rainSensorPin, INPUT);
  
  // Water level sensor পিন ইনিশিয়ালাইজ করুন
  pinMode(waterLevelPin, INPUT);
  
  // Wi-Fi কানেক্ট করা
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Rain sensor থেকে ডাটা পড়া
  int rainStatus = digitalRead(rainSensorPin);
  
  if (rainStatus == HIGH) {
    Serial.println("Rain detected!");  // Rain message print
  }

  // Water level sensor থেকে অ্যানালগ ডাটা পড়া
  int waterLevel = analogRead(waterLevelPin);
  
  // Water level দ্রুত বাড়লে সতর্কতা পাঠানো
  if (waterLevel > 500) { // এই মানটি আপনার সেন্সর অনুযায়ী পরিবর্তন করতে হবে
    unsigned long currentTime = millis();
    if (currentTime - lastTime > interval) {
      Serial.println("Water level rising quickly!");  // Water level alert print
      lastTime = currentTime;
    }
  }

  // Serial Monitor থেকে কমান্ড/বার্তা গ্রহণ করা
  if (Serial.available() > 0) {
    String receivedMessage = Serial.readString();  // সিরিয়াল থেকে ইনপুট গ্রহণ
    Serial.print("Received message: ");  // ইনপুট বার্তা প্রিন্ট করা
    Serial.println(receivedMessage);
    
    // যদি প্রাপ্ত বার্তা "RESET" হয়, তাহলে কিছু অ্যাকশন নেওয়া
    if (receivedMessage == "RESET") {
      Serial.println("System is resetting...");  // সিস্টেম রিসেট বার্তা প্রিন্ট
      // আপনি এখানে কোন ফাংশন কল করতে পারেন
    }
  }

  delay(1000); // 1 second delay before next reading
}

