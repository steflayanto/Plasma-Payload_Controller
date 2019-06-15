//For Trigger function.
unsigned long relayTimer;
boolean notYetCalled = true;
boolean turnedOff = false;

void relayInit() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  relayTimer = 0;
}

// Trigger is a non-blocking function which prints Active the first time it is called, then prints Off after a cerain duration
// that is specified with the paramter passed in. Repeated calls to trigger do nothing. UPDATE
void trigger(int duration, int pin) {
  if (notYetCalled) {
    digitalWrite(pin, HIGH);
    Serial.println("Active");
    relayTimer = millis();
    notYetCalled = false;
    digitalWrite(13,HIGH);
  } else if (millis() - relayTimer > duration && !turnedOff) {
    digitalWrite(pin, LOW);
    Serial.println(millis() - relayTimer);
    turnedOff = true;
    digitalWrite(13,LOW);
  }
}
