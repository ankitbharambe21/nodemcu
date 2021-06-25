#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "ANKIT";
const char* password = "21021996";
ESP8266WebServer server(80);

void handleRoot() 
{
server.send(200, "text/plain", "Acesss /lon page to turn on and /loff page to turn off");
}

void handleOn() 
{
digitalWrite(14, 0);
handleRoot();
}

void handleOff() 
{
digitalWrite(14, 1);
handleRoot();
}

void setup(void)
{
pinMode(14,OUTPUT);
digitalWrite(14,1);
Serial.begin(115200);
Serial.println();
Serial.print("Configuring access point...");
WiFi.softAP(ssid, password);
IPAddress myIP = WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(myIP);
server.on("/", handleRoot);
server.on("/lon", handleOn);
server.on("/loff", handleOff);
server.begin();
Serial.println("HTTP server started");
}
void loop(void)
{
server.handleClient();
}
