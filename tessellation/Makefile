# Author : Syed Saadat

CC = g++
LIBS = -lGL -lGLU -lglut -lm

all: dot

# This is the linking line
dot: dot.o
	$(CC) -o dot dot.o $(LIBS)

# This is the compilation line
dot.o: dot.cpp
	$(CC) -c dot.cpp 