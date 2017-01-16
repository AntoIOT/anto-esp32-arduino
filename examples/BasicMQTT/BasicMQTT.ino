#include <AntoIO.h>
#define LED 17

const char *ssid = "ssid";
const char *pass = "pass";
const char *user = "your-username";
const char *token = "token";
const char *thing = "thing";

/* create AntoIO instance */
AntoIO anto(user, token, thing);

void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  Serial.print("\nTrying to connect ");
  Serial.print(ssid);
  Serial.println("...");

  while (!anto.wifi.begin(ssid, pass));
  Serial.println("\nConnected, trying to connect to broker...");

  while (!anto.mqtt.connect(user, token, true));
  Serial.println("\nConnected");

  /* change "digital-channel" to your channel in switch type */
  anto.mqtt.sub("digital-channel");
}

void loop() {
  anto.mqtt.loop();
  /*
     for proper functionality,
     10-second delay should be added after loop()
  */
  delay(10);
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();

  if (payload.toInt() == 1) {
    digitalWrite(LED, HIGH);
    Serial.println("HIGH");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("LOW");
  }
}
