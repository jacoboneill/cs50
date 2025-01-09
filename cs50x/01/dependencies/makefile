CC = gcc
SRCS := $(wildcard *.c)
TARGETS := $(SRCS:.c=.out)

LIB_PATH = /Users/jacoboneill/Developer/cs50x/01/dependencies/libcs50
DYLIB_NAME = libcs50-11.0.2.dylib
LIB_NAME = cs50
LIB_SYM_PATH = $(LIB_PATH)/lib/$(DYLIB_NAME)
LIB_CFLAGS = -I$(LIB_PATH)/include -L$(LIB_PATH)/lib -l$(LIB_NAME)

CFLAGS = -Wall -Werror $(LIB_CFLAGS)

BUILD_DIR := ./build

all: $(TARGETS)

%.out: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<
	ln -fs $(LIB_SYM_PATH) $(BUILD_DIR)/$(DYLIB_NAME)

debug:
	@echo "debug: "
	@echo "LIB_REL_PATH: $(LIB_REL_PATH)"
	@echo "LIB_PATH: $(LIB_PATH)"
	@echo "LIB_CFLAGS: $(LIB_CFLAGS)"
	@echo "BUILD: $(CC) $(CFLAGS) -o"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean debug
