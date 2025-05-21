CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = utils.o


%: %.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

utils.o: utils.c
	$(CC) $(CFLAGS) -c $^ -o $@
