#include <Arduino.h>

#define POT_PIN 4
#define LED_PIN 22

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);

  ledcSetup(0, 5000, 8);
  ledcAttachPin(LED_PIN, 0);
}


int val = 0;
unsigned long prev = 0;
void loop() {
  if(millis() >= prev) {
    val = analogRead(POT_PIN);
    val = map(val, 0, 4095, 0, 255);
    
    ledcWrite(0, val);
    
    prev = millis() + 500;
  };
};