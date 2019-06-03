CC := gcc -g -Wall

DEFINES := -DGLFW
all: main.o

main.o: main.c
	$(CC) main.c -o PavonEngine.x64 $(DEFINES) -lglfw -lGL