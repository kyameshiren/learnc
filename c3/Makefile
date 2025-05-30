CC = gcc
CFLAGS = -Wall -Wextra -g 
OBJS = src/utils.o

%: %.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

src/utils.o: src/utils.c src/utils.h
	$(CC) $(CFLAGS) -c $< -o $@
