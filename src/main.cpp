#include <WiFi.h>
#include <FirebaseESP32.h>
 
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define FIREBASE_HOST "https://environment-meter-dragon-8bfae-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "096v54m4MCdog4gtln6jwoq912cS5Ik4CrnmHhsW"
#define WIFI_SSID "APTO101"
#define WIFI_PASSWORD "chmL231618"
 
 
//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;

String path = "/";
bool iterar = true;
 
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
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
 
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
 
  Serial.println("------------------------------------");
  Serial.println("Connected...");
  
}
 
void loop()
{
  while(iterar){
    Firebase.setInt(firebaseData, path + "/sensor1", 512);
    Firebase.setBool(firebaseData, path + "/online", true);
    Serial.println(firebaseData.intData());
    delay(250);
    iterar = false;
    Firebase.end(firebaseData);
  }
 
}