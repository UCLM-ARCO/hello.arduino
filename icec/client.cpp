// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <HardwareSerial.h>

#include <IceC/IceC.h>
#include <IceC/SerialEndpoint.h>
#include <IceC/platforms/arduino/debug.hpp>

#include "example.h"

Ice_Communicator ic;
Ice_ObjectPrx server;

int led = 13;
bool state = true;

void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(115200);
    while(!Serial);

    prints("\n\n---------------------------\n");

    Ice_initialize(&ic);
    IceC_Serial_init(&ic);

    Ice_Communicator_stringToProxy(&ic, "Server -d:serial", &server);
}

void loop() {
    digitalWrite(led, state);
    state = !state;

    Example_Hello_sayHello(&server);
    delay(1000);
}
