# Author : Syed Saadat

CC = g++
LIBS = -lGL -lGLU -lglut -lm

all: circle

# This is the linking line
circle: circle.o
	$(CC) -o circle circle.o $(LIBS)

# This is the compilation line
circle.o: circle.cpp
	$(CC) -c circle.cpp 