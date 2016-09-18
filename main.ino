void setup() {
    Serial.begin(9600);
    Serial1.begin(9600);
    Serial.setTimeout(300);
    Serial1.setTimeout(300);
}

String processLine(String line) {
    if (line.equals("v")) {
        return String("EBB Arduino Clone v0.1.0");
    }
    return NULL;
}

void loop() {
    String line = Serial.readStringUntil('\n');
    if (line != NULL) {
        // Pass on serial data
        Serial1.write("> " + line + "\n");
        String back = processLine(line.substring(0, line.length() - 1));
        if (back != NULL) {
            Serial.write(back + "\r\n");
            Serial1.write("< " + back + "\r\n");
        }
    }
}
