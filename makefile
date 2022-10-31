CC = g++
CFLAGS = -g -Wall

affixer: src/main.cpp word_loader.o
	$(CC) $(CFLAGS) src/main.cpp src/word_loader.o -o affixer

word_loader.o: src/noun.cpp
	$(CC) $(CFLAGS) -c src/word_loader.cpp -o src/word_loader.o
