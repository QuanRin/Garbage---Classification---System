#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "P3.T2.B";
const char *password = "28112773";

ESP8266WebServer server(80);

int ledPin = 2;

void setup()
{
    pinMode(ledPin, OUTPUT);

    WiFi.begin(ssid, password);
    Serial.begin(115200);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, handleRoot);
    server.on("/on", HTTP_GET, handleOn);
    server.on("/off", HTTP_GET, handleOff);

    // Đặt chức năng xử lý riêng cho "/ar/on"
    server.on("/ar/on", HTTP_GET, handleArduinoOn);
    server.on("/ar/off", HTTP_GET, handleArduinoOff);

    server.on("/ar/1", HTTP_GET, handleServerResult1);
    server.on("/ar/2", HTTP_GET, handleServerResult2);
    server.on("/ar/3", HTTP_GET, handleServerResult3);
    server.on("/ar/4", HTTP_GET, handleServerResult4);

    server.begin();
    Serial.println("Server started");
}

void loop()
{
    server.handleClient();
}

void handleRoot()
{
    String html = "<h1>Control the Light</h1>";
    html += "<button onclick='turnOn()'>Turn On Light</button>";
    html += "<button onclick='turnOff()'>Turn Off Light</button>";
    html += "<script>function turnOn(){window.location='/on';}</script>";
    html += "<script>function turnOff(){window.location='/off';}</script>";
    html += "<p><a href='/ar/on'>Turn On</a>&nbsp;<a href='/ar/off'>Turn Off</a></p>";

    server.send(200, "text/html", html);
}

void handleOn()
{
    digitalWrite(ledPin, HIGH);
    handleRoot(); // Gọi lại handleRoot để cập nhật giao diện
}

void handleOff()
{
    digitalWrite(ledPin, LOW);
    handleRoot(); // Gọi lại handleRoot để cập nhật giao diện
}

void handleArduinoOn()
{
    Serial.print("ledon");
    server.send(200, "text/html", "Sent command to Arduino: 1");
}

void handleArduinoOff()
{
    Serial.print("ledoff");
    server.send(200, "text/html", "Sent command to Arduino: 0");
}

void handleServerResult1()
{
    Serial.print("type1");
    server.send(200, "text/html", "Sent command to Arduino: type1");
}

void handleServerResult2()
{
    Serial.print("type2");
    server.send(200, "text/html", "Sent command to Arduino: type2");
}

void handleServerResult3()
{
    Serial.print("type3");
    server.send(200, "text/html", "Sent command to Arduino: type3");
}

void handleServerResult4()
{
    Serial.print("type4");
    server.send(200, "text/html", "Sent command to Arduino: type4");
}