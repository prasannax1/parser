CC = g++
CFLAGS = -std=c++11 -Wall

slice.o: slice.cpp slice.h
	$(CC) $(CFLAGS) -c slice.cpp
