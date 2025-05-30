CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
LDFLAGS = -lm

OBJS = src/op.o src/getch.o src/stack.o

polTarget: polTarget.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


