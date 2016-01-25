PROJECT_DIR = ~/cpp/arduino/cube
MONITOR_PORT = /dev/ttyACM0
BOARD_TAG = uno
SRCDIR = $(PROJECT_DIR)/src
LOCAL_C_SRCS ?= $(wildcard $(SRCDIR)/*.c)
LOCAL_CPP_SRCS ?= $(wildcard $(SRCDIR)/*.cpp)
LOCAL_CC_SRCS ?= $(wildcard $(SRCDIR)/*.cc)
LOCAL_INO_SRCS ?= $(wildcard $(SRCDIR)/*.ino)
LOCAL_AS_SRCS ?= $(wildcard $(SRCDIR)/*.S)

CFLAGS_STD = -std=c11
CXXFLAGS_STD = -std=c++11

CXXFLAGS = -pedantic -Wall -Wextra -fdiagnostics-color -fno-use-cxa-atexit
CXXFLAGS += -I/home/kyle/cpp/arduino/libraries/StandardCplusplus

include $(ARDMK_DIR)/Arduino.mk
