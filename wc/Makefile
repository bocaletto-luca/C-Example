CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -O2
TARGET   := wc-clone
SRC      := src/wc.c

all: $(TARGET)

$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f $(TARGET)

.PHONY: all clean
