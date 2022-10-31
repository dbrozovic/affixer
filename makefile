CC = g++
CFLAGS = -g -Wall

affixer: src/main.cpp noun.o
	$(CC) $(CFLAGS) src/main.cpp noun.o -o affixer

noun.o: src/noun.cpp
	$(CC) $(CFLAGS) -c src/noun.cpp -o noun.o
