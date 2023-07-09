# Author : Syed Saadat

CC = g++
LIBS = -lGL -lGLU -lglut -lm

all: spin

# This is the linking line
spin: spin.o
	$(CC) -o spin spin.o $(LIBS)

# This is the compilation line
spin.o: spin.cpp
	$(CC) -c spin.cpp 

# CC = gcc
# LIBDIRS = -L/usr/lib64
# INCDIRS = -I/usr/include
# LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

# spin: spin.o
# 	$(CC)  -o spin spin.o $(INCDIRS) $(LIBDIRS) $(LDLIBS)

# spin.o : spin.cpp
# 	$(CC)  -c spin.cpp $(INCDIRS)