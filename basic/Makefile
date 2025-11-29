CC = gcc
CFLAGS = -Iinclude -Wall -g

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)


all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

#tests:
# $(CC) $(CFLAGS) tests/test_array.c $(SRC) test_array

clean:
	rm -f src/*.o main test_*
