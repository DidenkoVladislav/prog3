CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = contstack.c main.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o main.out
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./main.out
