CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -O2
TARGET   := http-server
SRC      := src/server.c

all: $(TARGET)

$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $@ $^ -pthread

clean:
    rm -f $(TARGET)

.PHONY: all clean
