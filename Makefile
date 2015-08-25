CC=gcc
EXECUTABLE=main
LIBRARY=lib/libentity.a
MAINLIBS=-L./lib -lentity
OBJECTS=util.o mask.o world.o entity.o component.o system.o
INCLUDEDIR=./include

main: library main.c
	$(CC) -Wall -g -o $(EXECUTABLE) main.c -I $(INCLUDEDIR) $(MAINLIBS)

library: $(OBJECTS)
	mkdir -p lib
	ar -cvq $(LIBRARY) $(OBJECTS)

util.o: src/util.c $(INCLUDEDIR)/util.h
	$(CC) -c -g -Wall src/util.c -I $(INCLUDEDIR)

mask.o: src/mask.c $(INCLUDEDIR)/mask.h $(INCLUDEDIR)/util.h
	$(CC) -c -g -Wall src/mask.c -I $(INCLUDEDIR)

world.o: src/world.c $(INCLUDEDIR)/world.h $(INCLUDEDIR)/entity.h $(INCLUDEDIR)/mask.h $(INCLUDEDIR)/component.h
	$(CC) -c -g -Wall src/world.c -I $(INCLUDEDIR)

entity.o: src/entity.c $(INCLUDEDIR)/entity.h $(INCLUDEDIR)/mask.h $(INCLUDEDIR)/component.h $(INCLUDEDIR)/world.h
	$(CC) -c -g -Wall src/entity.c -I $(INCLUDEDIR)

component.o: src/component.c $(INCLUDEDIR)/component.h $(INCLUDEDIR)/entity.h $(INCLUDEDIR)/mask.h $(INCLUDEDIR)/util.h
	$(CC) -c -g -Wall src/component.c -I $(INCLUDEDIR)

system.o: src/system.c $(INCLUDEDIR)/system.h $(INCLUDEDIR)/util.h $(INCLUDEDIR)/mask.h $(INCLUDEDIR)/entity.h $(INCLUDEDIR)/component.h
	$(CC) -c -g -Wall src/system.c -I $(INCLUDEDIR)

run: main
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) $(LIBRARY)
