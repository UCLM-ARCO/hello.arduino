/* -*- mode: c++; coding: utf-8 -*- */

#include <TinkerKit.h>

TKLed led(O0);

void
setup() {
}

void
loop() {
    led.on();
    delay(50);
    led.off();
    delay(800);
}
