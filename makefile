CC = g++
CFLAGS = -std=c++11 -Wall

slicetest: slicetest.cpp slice.hpp
	$(CC) $(CFLAGS) -o slicetest slicetest.cpp
