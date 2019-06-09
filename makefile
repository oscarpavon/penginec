CC := cc -g -Wall

DEFINES := -DGLFW

export CC
export DEFINES

OBJs := vector.o windows.o
OBJs += file_loader.o
OBJs += ./renderer/renderer_opengl.o
OBJs += model.o
all: main.o 

main.o: main.c $(OBJs)
	$(CC) main.c -o PavonEngine.x64 $(OBJs) $(DEFINES) -lglfw -lEGL -lGLESv2 -lcglm

vector.o: vector.h vector.c
	$(CC) -c vector.c $(DEFINES)

windows.o: windows.h windows.c
	$(CC) -c windows.c $(DEFINES)

file_manager.o: file_loader.c file_loader.h
	$(CC) -c file_loader.c $(DEFINES)

renderer_opengl:
	$(MAKE) -C ./renderer

model.o: model.h model.c
	$(CC) -c model.c


.PHONY: clean
clean: clean_renderer
	rm -f *.o

.PHONY: clean_renderer
clean_renderer:
	cd renderer && rm -f *.o
