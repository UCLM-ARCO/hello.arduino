# -*- mode: makefile-gmake; coding: utf-8 -*-

# Arduino Pro or Pro Mini (5V, 16 MHz) w/ ATmega328
BOARD_TAG     = pro5v328
ARDUINO_DIR   = /usr/share/arduino

# You need the icec repo on user libraries dir
USER_LIB_PATH = $(HOME)/Arduino/libraries
ARDUINO_LIBS  = IceC stdsys

all: example.h

example.h: example.ice
	slice2c $^

vclean: clean
	rm example.h

include $(ARDUINO_DIR)/Arduino.mk

