CC = clang

SRC_DIR = src
BUILD_DIR = build

CFLAGS = -Wall -Wextra

SRCS = $(wildcard $(SRC_DIR)/*.c)
OUTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.out, $(SRCS))

all: $(OUTS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.out: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
