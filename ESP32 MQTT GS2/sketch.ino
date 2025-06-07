#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

const char* mqttPublishTopic = "enchentes/abrigos/abrigo01";
const char* mqttBuzzerTopic = "enchentes/abrigos/abrigo01/buzzer";

WiFiClient espClient;
PubSubClient client(espClient);

#define BUZZER_PIN 13

// Callback: executado quando recebe mensagem
void callback(char* topic, byte* payload, unsigned int length) {
  String mensagem;
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }

  Serial.print("Mensagem recebida no tópico ");
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(mensagem);

  if (String(topic) == mqttBuzzerTopic) {
    if (mensagem == "ligar") {
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("Buzzer ligado manualmente via dashboard.");
    } else if (mensagem == "desligar") {
      digitalWrite(BUZZER_PIN, LOW);
      Serial.println("Buzzer desligado manualmente via dashboard.");
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado.");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar MQTT...");
    if (client.connect("clientId-wokwi-abrigo01")) {
      Serial.println("Conectado!");
      client.subscribe(mqttBuzzerTopic);
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float temperatura = random(200, 350) / 10.0;
  int umidade = random(50, 100);
  int nivelAgua = random(0, 4095);

  if (nivelAgua > 3000) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("🚨 Nível crítico de água! Buzzer acionado.");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  String payload = "{\"temperatura\":";
  payload += temperatura;
  payload += ",\"umidade\":";
  payload += umidade;
  payload += ",\"nivel_agua\":";
  payload += nivelAgua;
  payload += "}";

  Serial.println("Publicando: " + payload);
  client.publish(mqttPublishTopic, payload.c_str());

  delay(5000);
}
