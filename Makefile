CC = gcc
CFLAGS = -Wall -Wextra -g 
LDFLAGS = -lm


%: %.c
	$(CC) $(CFLAGS) $^ -o $@

default: default.c 
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

utils.o: src/utils.c src/utils.h
	$(CC) $(CFLAGS) -c $< -o $@
