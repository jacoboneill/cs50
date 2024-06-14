CC = gcc
SRCS := $(wildcard *.c)
TARGETS := $(SRCS:.c=.out)

cs50 = 0
LIB_PATH = /Users/jacoboneill/Developer/cs50x/01/dependencies/libcs50
DYLIB_NAME = libcs50-11.0.2.dylib
LIB_NAME = cs50
LIB_SYM_PATH = $(LIB_PATH)/lib/$(DYLIB_NAME)
LIB_CFLAGS = -I$(LIB_PATH)/include -L$(LIB_PATH)/lib -l$(LIB_NAME)

CFLAGS = -Wall -Werror
ifeq ($(cs50), 1)
	CFLAGS += $(LIB_CFLAGS)
endif

BUILD_DIR := ./build

all: $(TARGETS)

%.out: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<
	@if [ $(cs50) -eq 1 ]; then $(MAKE) symlink; fi

symlink:
	@ln -fs $(LIB_SYM_PATH) $(BUILD_DIR)/$(DYLIB_NAME)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean symlink
