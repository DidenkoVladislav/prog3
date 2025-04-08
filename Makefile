CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = bitrgbled.c matrix2d.c contqueue.c main.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o main.out
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./main.out
