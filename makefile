CC := gcc -g -Wall

DEFINES := -DGLFW

OBJs := vector.o windows.o

all: main.o 

main.o: main.c $(OBJs)
	$(CC) main.c -o PavonEngine.x64 $(OBJs) $(DEFINES) -lglfw -lEGL -lGLESv2

vector.o: vector.h vector.c
	$(CC) -c vector.c $(DEFINES)

windows.o:	windows.h windows.c
	$(CC) -c windows.c $(DEFINES)


.PHONY: clean
clean:
	rm -f *.o