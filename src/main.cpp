#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Firebase_ESP_Client.h>
 
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define DATABASE_URL "https://environment-meter-dragon-8bfae-default-rtdb.firebaseio.com/"
#define WIFI_SSID "APTO101"
#define WIFI_PASSWORD "chmL231618"
#define API_KEY "AIzaSyDaFthn4MtUa-Z86epaoygFa7JtfW084FE"
 
//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;
FirebaseAuth auth;
FirebaseConfig config;

bool signedUp = false;
unsigned long sendDataPrevMillis = 0;
 
void setup()
{
 
  Serial.begin(115200);
  Serial.println();
 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
 
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
 
  Serial.println("------------------------------------");
  Serial.println("Connected...");
  
}
 
void loop()
{

  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();
    
    if (Firebase.RTDB.setInt(&firebaseData, "/sensor1", 512)){
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
    }
    
    
    if (Firebase.RTDB.setBool(&firebaseData, "/online", true)){
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
    }
  }
 
}