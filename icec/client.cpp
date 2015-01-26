// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <HardwareSerial.h>

#include <IceC/IceC.h>
#include "example.h"

Ice_Communicator ic;
Ice_ObjectPrx server;

int led = 13;
bool state = true;

extern "C" {
    void prints(const char* msg) { Serial.print(msg); }
    void printi(const int v) { Serial.print(v); }
}

void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(115200);
    while(!Serial);

    prints("\n\n---------------------------\n");

    Ice_initialize(&ic);
    Ice_Communicator_stringToProxy(&ic, "Server -t:sample", &server);
}

void loop() {
    digitalWrite(led, state);
    state = !state;

    // Example_Hello_sayHello(&server);
    delay(1000);
}
