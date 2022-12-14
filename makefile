CC = g++
CFLAGS = -g -Wall

affixer: src/main.cpp src/word_loader.o
	$(CC) $(CFLAGS) src/main.cpp src/word_loader.o -o affixer

src/word_loader.o: src/word_loader.cpp
	$(CC) $(CFLAGS) -c src/word_loader.cpp -o src/word_loader.o
