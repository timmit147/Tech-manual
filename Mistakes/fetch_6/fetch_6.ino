#include "ESP8266WiFi.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
# define LED D4 // Use built-in LED which connected to D4 pin or GPIO 2

String serverName = "http://abcdxyz.xyz/";
unsigned long timerDelay = 5000;
unsigned long lastTime = 0;


// WiFi parameters to be configured
const char* ssid = "Ziggo11550";
const char* password = "VRfquHFATPyu";


void setup() {
  pinMode(LED, OUTPUT);     // Initialize the LED as an output
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

}
void loop() {

  //Calling An URL FOR DATA


   if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 int randNumber = random(1, 99999);

 String crow = "https://www.example.com/";
 crow += randNumber;
 Serial.println(crow);


http.begin(crow); //Specify the URL

    int httpCode = http.GET();     //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(1000);

  //Calling URL ENDS
digitalWrite(LED, HIGH);
delay(100);
digitalWrite(LED, LOW);

}
