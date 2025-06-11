CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -O2
TARGET   := calc
SRC      := src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f $(TARGET)

.PHONY: all clean
