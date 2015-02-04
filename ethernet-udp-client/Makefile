# -*- mode: makefile-gmake; coding: utf-8 -*-

# Arduino Ethernet
BOARD_TAG     = ethernet
USER_LIB_PATH = $(HOME)/Arduino/libraries
ARDUINO_DIR   = /usr/share/arduino
ARDUINO_LIBS  = SPI Ethernet

# If you have annoying messages on some Arduino libraries...
CFLAGS       += -Wno-unused-function -Wno-unused-variable
CFLAGS       +=	-Wno-unused-but-set-variable -Wno-strict-aliasing
CXXFLAGS      = $(CFLAGS)

include $(ARDUINO_DIR)/Arduino.mk

