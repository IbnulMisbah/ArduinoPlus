// Bismillahir Rahmanir Rahim 

#include <WiFi.h>
#include <ESP32_MailClient.h>

// পিন ডেফিনেশন
const int rainSensorPin = 14;    // Rain sensor connected to GPIO 14
const int waterLevelPin = 34;    // Water level sensor connected to GPIO 34 (Analog pin)

// Wi-Fi credentials
const char* ssid = "Ismail Al Jazari";
const char* password = "hizbullah";

// ইমেইল তথ্য
#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 465  // 465 for SSL, 587 for TLS
#define EMAIL_ADDRESS "abdullahibnulmisbah@gmail.com"
#define EMAIL_PASSWORD "qsiy eokz mhyq nllt"  // Gmail App Password

// ইমেইল পাঠানোর জন্য প্রাপক
#define EMAIL_RECIPIENT "abdullahibnulmisbah@gmail.com"

// SMTP Client
SMTPSession smtp;

unsigned long lastTime = 0;
unsigned long interval = 180000; // 3 minutes in milliseconds (3 minutes interval for water level rising)

void setup() {
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

  // SMTP সেটআপ
  SMTP_Auth auth;
  auth.login = EMAIL_ADDRESS;
  auth.password = EMAIL_PASSWORD;
  
  smtp.debug(1);
  smtp.callback(smtpCallback);

  // SMTP সেটিংস
  smtp.config(SMTP_SERVER, SMTP_PORT, auth);
}

void loop() {
  // Rain sensor থেকে ডাটা পড়া
  int rainStatus = digitalRead(rainSensorPin);
  
  if (rainStatus == HIGH) {
    Serial.println("Rain detected!");
    sendEmail("Rain detected!", "It is raining!");  // Rain email
  }

  // Water level sensor থেকে অ্যানালগ ডাটা পড়া
  int waterLevel = analogRead(waterLevelPin);
  
  if (waterLevel > 500) { // এই মানটি আপনার সেন্সর অনুযায়ী পরিবর্তন করতে হবে
    unsigned long currentTime = millis();
    if (currentTime - lastTime > interval) {
      Serial.println("Water level rising quickly!");
      sendEmail("Water level rising quickly!", "Water level is increasing rapidly!");  // Water level email
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
      Serial.println("System is resetting...");
      sendEmail("System Reset", "The system is being reset.");  // Reset email
    }
  }

  delay(1000); // 1 second delay before next reading
}

// ইমেইল পাঠানোর ফাংশন
void sendEmail(String subject, String body) {
  SMTPMessage message;
  message.sender.name = "ESP32";
  message.sender.email = EMAIL_ADDRESS;
  message.subject = subject;
  message.addRecipient(EMAIL_RECIPIENT);
  message.text.content = body;

  if (!smtp.sendMail(message)) {
    Serial.println("Error sending email: " + smtp.errorReason());
  } else {
    Serial.println("Email sent successfully!");
  }
}

// SMTP Callback Function
void smtpCallback(SMTP_Status status) {
  if (status.info.length() > 0) {
    Serial.println(status.info);
  }
  if (status.error.length() > 0) {
    Serial.println("Error: " + status.error);
  }
}

