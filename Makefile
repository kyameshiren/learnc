CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
OBJS = src/utils.o


%: %.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

default: default.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): src/utils.c src/utils.h
	$(CC) $(CFLAGS) -c $< -o $@
