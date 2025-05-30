CC = gcc
CFLAGS = -Wall -Wextra -g 


default: default.c 
	$(CC) $(CFLAGS) $^ -o $@
