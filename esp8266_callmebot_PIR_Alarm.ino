#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>
const char* ssid = "Router SSID(name)";
const char* password = "Router password";

String phoneNumber = "+40xxxxxxxxx"; //Phone number. Include the country prefix, such as +40 for Romania
String apiKey = "your API Key";
//--------------------------------------------
void sendMessage(String message){
   // Data to send with HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
   WiFiClient client;    
   HTTPClient http;
   http.begin(client, url);

   // Specify content-type header
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
   // Send HTTP POST request
   int httpResponseCode = http.POST(url);
   if (httpResponseCode == 200){
     Serial.print("Message sent successfully");
     } else {
     Serial.println("Error sending the message");
     Serial.print("HTTP response code: ");
     Serial.println(httpResponseCode);
   }
     // Free resources
     http.end();
  }
//-----------------------------------------
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
   }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    // Send Message to WhatsAPP
    sendMessage("Message to send when the sensor detects presence");  //your message
  }
//-----------------------------------
void loop() {
 }
//=============================
