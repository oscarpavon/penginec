CC := gcc -g -Wall

DEFINES := -DGLFW
all: main.o 

main.o: main.c vector.o
	$(CC) main.c -o PavonEngine.x64 vector.o $(DEFINES) -lglfw -lGL

vector.o: vector.h vector.c
	$(CC) -c vector.c