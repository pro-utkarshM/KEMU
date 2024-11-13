flags = -O2 -Wall -std=c2x
ldflags = -L../utils/bin -lkemu_utils

.PHONY: all clean

all: clean kemu

kemu: kemu.o
	cc $(flags) $^ -o $@ $(ldflags)

kemu.o: kemu.c kemu.h
	cc $(flags) -c $< -o $@

clean:
	rm -f *.o kemu
