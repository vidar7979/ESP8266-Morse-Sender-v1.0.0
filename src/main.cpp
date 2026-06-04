#include <Arduino.h>

// ESP8266 Morse LED sender
// Sends START + IP + MAC + STOP

// LED connected to D5
const int LED_PIN = D5;

// Morse speed ( The Device will work on 150ms unit time, which is a common speed for Morse code in Dev 4.2.1 and above
const int unitMs = 120;

// Message with START(<), separators, and STOP(>)
String message =
    "<IP:192.168.1.101|"
    "MAC:BB:1A:2B:3C:4D:5E|"
    "SUBNET:255.255.255.0>";

void sendMessage(String text);
void sendMorse(const char* morse);
const char* getMorse(char c);
void setup() {

    // Setup LED pin
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    // Wait before sending
    delay(3000);

    sendMessage(message);
}

void loop() {

    // Send only once
}

void sendMessage(String text) {

    for (int i = 0; i < text.length(); i++) {

        char c = text.charAt(i);

        // Make lowercase uppercase
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }

        const char* morse = getMorse(c);

        if (morse != nullptr) {
            sendMorse(morse);

            // Letter space
            delay(unitMs * 3);
        }
    }
}

void sendMorse(const char* morse) {

    for (int i = 0; morse[i] != '\0'; i++) {

        // LED ON
        digitalWrite(LED_PIN, HIGH);

        if (morse[i] == '.') {
            delay(unitMs);
        } else if (morse[i] == '-') {
            delay(unitMs * 3);
        }

        // LED OFF
        digitalWrite(LED_PIN, LOW);

        // Space between signals
        delay(unitMs);
    }
}

const char* getMorse(char c) {

    // START marker
    if (c == '<') return "-.-.-";

    // STOP marker
    if (c == '>') return "...---";

    // New line marker
    if (c == '\n') return "-...-";

    // Space marker
    if (c == ' ') return "......";
    
    // Separator marker
    if (c == '|') return "-....-";

    // Letters
    if (c == 'A') return ".-";
    if (c == 'B') return "-...";
    if (c == 'C') return "-.-.";
    if (c == 'D') return "-..";
    if (c == 'E') return ".";
    if (c == 'F') return "..-.";
    if (c == 'G') return "--.";
    if (c == 'H') return "....";
    if (c == 'I') return "..";
    if (c == 'J') return ".---";
    if (c == 'K') return "-.-";
    if (c == 'L') return ".-..";
    if (c == 'M') return "--";
    if (c == 'N') return "-.";
    if (c == 'O') return "---";
    if (c == 'P') return ".--.";
    if (c == 'Q') return "--.-";
    if (c == 'R') return ".-.";
    if (c == 'S') return "...";
    if (c == 'T') return "-";
    if (c == 'U') return "..-";
    if (c == 'V') return "...-";
    if (c == 'W') return ".--";
    if (c == 'X') return "-..-";
    if (c == 'Y') return "-.--";
    if (c == 'Z') return "--..";

    // Numbers
    if (c == '0') return "-----";
    if (c == '1') return ".----";
    if (c == '2') return "..---";
    if (c == '3') return "...--";
    if (c == '4') return "....-";
    if (c == '5') return ".....";
    if (c == '6') return "-....";
    if (c == '7') return "--...";
    if (c == '8') return "---..";
    if (c == '9') return "----.";

    // Symbols
    if (c == '.') return ".-.-.-";
    if (c == ':') return "---...";

    // Unknown
    return nullptr;
}