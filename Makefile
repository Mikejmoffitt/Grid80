CC=clang
CFLAGS= -Wall -Wextra -Werror -pedantic -O2 -pipe -march=native
INCLUDE= -I./include

.PHONY: all
all: grid80

grid80: src/main.c map.o print.o put.o
	$(CC) $(CFLAGS) $(INCLUDE) src/main.c map.o print.o put.o -o grid80

map.o: src/map.c
	$(CC) -c $(CFLAGS) $(INCLUDE) src/map.c

print.o: src/print.c
	$(CC) -c $(CFLAGS) $(INCLUDE) src/print.c

put.o: src/put.c
	$(CC) -c $(CFLAGS) $(INCLUDE) src/put.c

.PHONY: clean
clean:
	rm -f grid80
	rm -f *.o
