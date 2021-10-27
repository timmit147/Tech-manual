#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


const char* ssid = "Ziggo11550";
const char* password = "VRfquHFATPyu";

const char* url = "https://api.angelcam.com/v1/events/";
const char* fingerprint = "51 87 10 92 52 38 41 A9 SD 23 V3 23 72 58 SE EF 06 8D 35 4C";

void setup() {
 unsigned short count = 0; 
 
 Serial.begin(115200);
 
 Serial.println();
 
 Serial.print("Connecting to ");
 Serial.println(ssid);
 
 WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
   count++;

   if (count >= 30)
      wifiRestart();
 }
 
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
}


void wifiRestart(){
 Serial.println("Turning WiFi off...");
 WiFi.mode(WIFI_OFF);
 Serial.println("Sleepping for 10 seconds...");
 delay(10000);
 Serial.println("Trying to connect to WiFi...");
 WiFi.mode(WIFI_STA);
}


void loop() {
 Serial.println("test");
 short response_code = 0;
 
 // wait for WiFi connection
 if ((WiFi.status() == WL_CONNECTED)) {
   HTTPClient http;

   Serial.print("[HTTPS] begin...\n");

   http.begin(url, fingerprint);
   http.addHeader("Content-Type", "application/json");
  
   int httpCode = http.POST("{\"hash\": \"34jh34uh3v\"}");
   if (httpCode > 0) {
     http.writeToStream(&Serial);

     // HTTP header has been send and Server response header has been handled
     Serial.printf("[HTTP] ... code: %d\n", httpCode);

     // file found at server
     if (httpCode >= 200 and httpCode <= 299) {
       response_code = 1;
       String payload = http.getString();
       Serial.println(payload);
     }
   } 
   else {
     Serial.printf("[HTTP] ... failed, error: %s\n", http.errorToString(httpCode).c_str());
   }
   
   http.end();
 }
 else {
   wifiRestart();
 }

 if (response_code){
   Serial.println("All fine. Going to sleep...");
   ESP.deepSleep(0);
 }

}
