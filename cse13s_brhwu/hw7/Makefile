CC = clang

# CFLAGS =

CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: businessdb

businessdb: businessdb.o hashtable.o
	$(CC) hashtable.o businessdb.o -o businessdb

hashtable.o: hashtable.c hashtable.h
	$(CC) $(CFLAGS) -c hashtable.c

businessdb.o: businessdb.c hashtable.h
	$(CC) $(CFLAGS) -c businessdb.c

clean:
	rm -f businessdb businessdb.o hashtable.o

format:
	clang-format -i -style=file *.{c,h}

