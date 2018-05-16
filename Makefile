# Makefile for Game_2048
# Amy Feng
# 5/16/2018

CPP = g++
CC = gcc
CFLAGS = -c 

game: main.o board.o userInput.o
	$(CPP) board.o main.o userInput.o -o game
main.o: main.cpp
	$(CPP) $(CFLAGS) main.cpp
board.o: board.cpp
	$(CPP) $(CFLAGS) board.cpp
userInput.o: userInput.cpp
	$(CPP) $(CFLAGS) userInput.cpp
clean: 
	rm -rf *.o

