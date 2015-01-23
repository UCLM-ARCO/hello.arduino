// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <IceC/IceC.h>
#include "example.h"

Ice_Communicator ic;
Ice_ObjectPrx server;

int led = 13;
bool state = true;

void setup() {
    pinMode(led, OUTPUT);

    Ice_initialize(&ic);
    Ice_Communicator_stringToProxy(&ic, "Server -t:sample", &server);
}

void loop() {
    digitalWrite(led, state);
    state = !state;

    Example_Hello_sayHello(&server);
    delay(1000);
}
