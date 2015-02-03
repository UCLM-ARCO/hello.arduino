// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>

void
setup() {
}

void
loop() {
}



// #include <IceC/IceC.h>
// #include <IceC/SerialEndpoint.h>

// // For DEBUG only
// // #include <IceC/platforms/arduino/debug.hpp>

// #include "example.h"

// Ice_Communicator ic;
// Ice_ObjectAdapter adapter;
// Example_Hello servant;

// char led = 13;

// void
// Example_HelloI_sayHello(Example_HelloPtr self) {
//     static bool state = false;
//     digitalWrite(led, state);
//     state = !state;
// }

// void setup() {
//     pinMode(led, OUTPUT);
//     // debug_init();

//     digitalWrite(led, true);
//     delay(1000);
//     digitalWrite(led, false);

//     Ice_initialize(&ic);
//     IceC_Serial_init(&ic);

//     Ice_Communicator_createObjectAdapterWithEndpoints
//     	(&ic, "Adapter", "serial", &adapter);
//     Ice_ObjectAdapter_activate(&adapter);

//     Example_Hello_init(&servant);
//     Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "Server");

//     Ice_Communicator_waitForShutdown(&ic);
// }

// void loop() {
//     digitalWrite(led, true);
//     delay(1000);
// }
