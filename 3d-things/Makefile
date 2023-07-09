# Author : Syed Saadat
# Compile by typing "make" and run by typing "./house"

CC = g++
LDLIBS = -lglut -lGL -lGLU -lm
OBJS = init.o display.o drawFuncs.o keyboard.o mouse.o defineHouse.o spinDisplay.o reshape.o globals.o menu.o mathFuncs.o convertCam.o setCamMode.o reset.o
HEADERS = opengl.h structs.h globals.h prototypes.h

all: house 

house : main.o $(OBJS)
	$(CC) -o house main.o $(OBJS) $(LDLIBS)

main.o : main.cpp $(HEADERS);
	$(CC) -c main.cpp

global.o : global.cpp $(HEADERS)
	$(CC) -c global.cpp

init.o : init.cpp $(HEADERS)
	$(CC) -c init.cpp 

display.o : display.cpp $(HEADERS)
	$(CC) -c display.cpp

drawFuncs.o : drawFuncs.cpp $(HEADERS)
	$(CC) -c drawFuncs.cpp

keyboard.o : keyboard.cpp $(HEADERS)
	$(CC) -c keyboard.cpp

mouse.o : mouse.cpp $(HEADERS)
	$(CC) -c mouse.cpp

defineHouse.o : defineHouse.cpp $(HEADERS)
	$(CC) -c defineHouse.cpp

spinDisplay.o : spinDisplay.cpp $(HEADERS)
	$(CC) -c spinDisplay.cpp

reshape.o : reshape.cpp $(HEADERS)
	$(CC) -c reshape.cpp

menu.o : menu.cpp $(HEADERS)
	$(CC) -c menu.cpp

mathFuncs.o : mathFuncs.cpp $(HEADERS)
	$(CC) -c mathFuncs.cpp
	
convertCam.o : convertCam.cpp $(HEADERS)
	$(CC) -c convertCam.cpp

setCamMode.o : setCamMode.cpp $(HEADERS)
	$(CC) -c setCamMode.cpp

reset.o : reset.cpp $(HEADERS)
	$(CC) -c reset.cpp

clean:
	rm *.o

pristine:
	rm *.o
	touch *
