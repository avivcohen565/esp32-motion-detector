#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_NAME"; 
const char* password = "YOUR_WIFI_PASSWORD";

String botToken = "YOUR_BOT_TOKEN";
String chatId = "YOUR_ID_TELEGRAM"; 

int pirPin = 13; 
int buttonPin = 4; 

int pirState = LOW;
int lastPirState = LOW;
int lastButtonState = HIGH;
bool isSystemArmed = false;

unsigned long armedTime = 0;       
unsigned long lastAlertTime = 0;    
const unsigned long gracePeriod = 5000;
const unsigned long alertDelay = 60000; 

bool isFirstAlert = true; 

WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi!");
  client.setInsecure(); 
  Serial.println("System Ready. Press the button to ARM.");
}

void sendMessage(String text) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatId + "&text=" + text;
    http.begin(client, url);
    http.GET();
    http.end();
  }
}

void loop() {

  int currentButtonState = digitalRead(buttonPin);
  
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    delay(200); 
    
    isSystemArmed = !isSystemArmed; 
    
    if (isSystemArmed) {
      Serial.println("System ARMED 🛡️");
      sendMessage("🛡️ המערכת פועלת חיישן התנועה יופעל בעוד 5 שניות.");
      
      armedTime = millis(); 
      isFirstAlert = true;  
    } else {
      Serial.println("System DISARMED 🛑");
      sendMessage("🛑 המערכת כובתה. החיישן מנוטרל.");
    }
  }
  lastButtonState = currentButtonState;

  if (isSystemArmed) {
    if (millis() - armedTime > gracePeriod) {
      pirState = digitalRead(pirPin);
      
      if (pirState == HIGH && lastPirState == LOW) {
        
        if (isFirstAlert || (millis() - lastAlertTime > alertDelay)) {
          Serial.println("Motion Detected! Sending alert...");
          sendMessage("🚨 זיהוי תנועה בחדר! 🚨");
          
          lastAlertTime = millis(); 
          isFirstAlert = false;   
        }
        
        lastPirState = HIGH;
      } 
      else if (pirState == LOW) {
        lastPirState = LOW;
      }
    }
  }
}