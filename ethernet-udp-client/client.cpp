// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <Ethernet.h>

EthernetUDP udp;

void
setup() {
    // put here your device MAC address (see below it)
    byte mac[] = {0x90, 0xa2, 0xda, 0x00, 0xf4, 0xe3};

    // change according to your network settings
    byte myip[] = {192, 168, 0, 5};

    Ethernet.begin(mac, myip);
    udp.begin(1234);
}

void
loop() {
    // put here your remote ip address
    byte serverip[] = {192, 168, 0, 4};

    udp.beginPacket(serverip, 5555);
    udp.write("Hello from Arduino!\n");
    udp.endPacket();

    while(1);
}

