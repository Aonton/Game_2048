# Makefile for Game_2048
# Amy Feng
# 5/16/2018
# TO DO: CLEAN UP MAKEFILE

CPP = g++
CC = gcc
CFLAGS = -c 

game: main.o board.o userInput.o pieceGenerator.o collision.o position.o score.o game2048.o
	$(CPP) board.o main.o userInput.o pieceGenerator.o collision.o position.o score.o game2048.o -o game 
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
score.o: score.cpp
	$(CPP) $(CFLAGS) score.cpp
game2048.o: game2048.cpp
	$(CPP) $(CFLAGS) game2048.cpp
clean: 
	rm -rf *.o

