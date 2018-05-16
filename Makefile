# Makefile for Game_2048
# Amy Feng
# 5/16/2018

CPP = g++
CC = gcc
CFLAGS = -c 

game: main.o board.o 
	$(CPP) board.o main.o -o game
main.o: main.cpp
	$(CPP) $(CFLAGS) main.cpp

board.o: board.cpp
	$(CPP) $(CFLAGS) board.cpp
clean: 
	rm -rf *.o

