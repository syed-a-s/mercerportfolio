# Author : Syed Saadat

CC = g++
LIBS = -lGL -lGLU -lglut -lm

all: clip

# This is the linking line
clip: clip.o
	$(CC) -o clip clip.o $(LIBS)

# This is the compilation line
clip.o: clip.cpp
	$(CC) -c clip.cpp 