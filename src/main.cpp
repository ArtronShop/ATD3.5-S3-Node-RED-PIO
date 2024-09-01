#include <Arduino.h>
#include <lvgl.h>
#include <ATD3.5-S3.h>
#include "gui/ui.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <PubSubClient.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 1;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

const char* ssid = "CYD1";
const char* password = "12345678";
const char* mqtt_server = "broker.emqx.io";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  // Setup peripherals
  Display.begin(0); // rotation number 0
  Touch.begin();
  Sound.begin();
  // Card.begin(); // uncomment if you want to Read/Write/Play/Load file in MicroSD Card
  sensors.begin();

  // Map peripheral to LVGL
  Display.useLVGL(); // Map display to LVGL
  Touch.useLVGL(); // Map touch screen to LVGL
  Sound.useLVGL(); // Map speaker to LVGL
  // Card.useLVGL(); // Map MicroSD Card to LVGL File System

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  Display.enableAutoSleep(120); // Auto off display if not touch in 2 min
  
  // Add load your UI function
  ui_init();

  // Add event handle
  lv_timer_create([](lv_timer_t * timer) {
    sensors.requestTemperatures(); 
    float temperatureC = sensors.getTempCByIndex(0);
    Serial.print(temperatureC);
    Serial.println("ºC");

    lv_label_set_text_fmt(ui_temp_label, "%.01f", temperatureC);
    lv_arc_set_value(ui_temp_arc, (int16_t)(temperatureC * 10));
    client.publish("/ArtronShop/Sensor/1", String(temperatureC).c_str());
  }, 5000, NULL);
}

void loop() {
  Display.loop(); // Keep GUI work

  // MQTT
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
