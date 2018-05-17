# Makefile for Game_2048
# Amy Feng
# 5/16/2018

CPP = g++
CC = gcc
CFLAGS = -c 

game: main.o board.o userInput.o pieceGenerator.o collision.o position.o 
	$(CPP) board.o main.o userInput.o pieceGenerator.o collision.o position.o -o game 
main.o: main.cpp
	$(CPP) $(CFLAGS) main.cpp
board.o: board.cpp
	$(CPP) $(CFLAGS) board.cpp
userInput.o: userInput.cpp
	$(CPP) $(CFLAGS) userInput.cpp
pieceGenerator.o: pieceGenerator.cpp
	$(CPP) $(CFLAGS) pieceGenerator.cpp
collision.o: collision.cpp
	$(CPP) $(CFLAGS) collision.cpp
position.o: position.cpp
	$(CPP) $(CFLAGS) position.cpp
clean: 
	rm -rf *.o

