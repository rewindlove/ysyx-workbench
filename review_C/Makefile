CFILES := $(wildcard *.c)
EXES := $(patsubst %.c, %, $(CFILES))
CC=gcc
CFLAGS=-Wall -g
%:%.c
	$(CC) $(CFLAGS) -o $* $<
all:$(EXES)
	
clean:
	rm -rf $(EXES)

.PHONY:all clean
