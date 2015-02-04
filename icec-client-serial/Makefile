# -*- mode: makefile-gmake; coding: utf-8 -*-

# Arduino Pro or Pro Mini (5V, 16 MHz) w/ ATmega328
# BOARD_TAG     = pro5v328

# Arduino Duemilanove w/ ATmega328
BOARD_TAG     = atmega328
ARDUINO_DIR   = /usr/share/arduino

# You need the icec repo on user libraries dir
USER_LIB_PATH = $(HOME)/Arduino/libraries
ARDUINO_LIBS  = IceC SerialEndpoint

# CFLAGS        = -DDEBUG
CFLAGS       += -Wno-unused-function -Wno-unused-variable
CXXFLAGS      = $(CFLAGS)

all: example.h

example.h: example.ice
	slice2c $^

vclean: clean
	rm -frv example.h

include $(ARDUINO_DIR)/Arduino.mk

