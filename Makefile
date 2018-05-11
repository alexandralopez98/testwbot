CC = gcc
CFLAGS = -g -gdwarf-2 -Wall -std=gnu++11
TARGETS = main

all: $(TARGETS)

%.o: %.c queue.h
	$(CC) $(CFLAGS)

clean:
	rm -f $(TARGETS)
