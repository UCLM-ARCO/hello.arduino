// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <HardwareSerial.h>

#include <IceC/IceC.h>
#include <IceC/SerialEndpoint.h>

// For DEBUG only
// #include <IceC/platforms/arduino/debug.hpp>

#include "example.h"

Ice_Communicator ic;
Ice_ObjectPrx server;

int led = 13;
bool status = true;

void setup() {
    pinMode(led, OUTPUT);
    // debug_init();

    Ice_initialize(&ic);
    IceC_Serial_init(&ic);

    Ice_Communicator_stringToProxy(&ic, "Server -d:serial", &server);
}

void loop() {
    digitalWrite(led, status);
    status = !status;

    Example_Hello_sayHello(&server);
    delay(1000);
}
