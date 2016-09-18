void setup() {
    Serial.begin(9600);
    Serial.setTimeout(1000);
}

void loop() {
    String line = Serial.readStringUntil('\r'); // Start of \r\n
    if (line != NULL) {
        Serial.read(); // Remove \n from buffer
        Particle.publish("serialLine", line);
    }
}
