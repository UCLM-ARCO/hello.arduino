// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <TinkerKit.h>
#include <IceC/IceC.h>

// #include <IceC/SerialEndpoint.h>

// For DEBUG only
#include <IceC/platforms/arduino/debug.hpp>

#include "example.h"

Ice_Communicator ic;
Ice_ObjectAdapter adapter;
Example_Light servant;

byte led = 9;
TKLed light(O0);

void
Example_LightI_sayHello(Example_LightPtr self, Ice_Bool state) {
    light.write(state);
}

void setup() {
    pinMode(led, OUTPUT);
    debug_init();

    digitalWrite(led, true);
    delay(1000);
    digitalWrite(led, false);

    Ice_initialize(&ic);
    // IceC_Serial_init(&ic);

    Ice_Communicator_createObjectAdapterWithEndpoints
     	(&ic, "Adapter", "udp -h 127.0.0.1 -p 7788", &adapter);
    Ice_ObjectAdapter_activate(&adapter);

    Example_Light_init(&servant);
    Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "Light");

    Ice_Communicator_waitForShutdown(&ic);
}

void loop() {
}
