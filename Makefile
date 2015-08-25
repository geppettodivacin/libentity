CC=gcc
EXECUTABLE=main
LIBRARY=libentity.a
OBJECTS=util.o mask.o world.o entity.o component.o system.o

main: $(OBJECTS) main.c
	$(CC) -Wall -g -o $(EXECUTABLE) $(OBJECTS) main.c

library: $(OBJECTS)
	ar -cvq $(LIBRARY) $(OBJECTS)

util.o: util.c util.h
	$(CC) -c -g -Wall util.c

mask.o: mask.c mask.h util.h
	$(CC) -c -g -Wall mask.c

world.o: world.c world.h entity.h mask.h component.h
	$(CC) -c -g -Wall world.c

entity.o: entity.c entity.h mask.h component.h world.h
	$(CC) -c -g -Wall entity.c

component.o: component.c component.h entity.h mask.h util.h
	$(CC) -c -g -Wall component.c

system.o: system.c system.h util.h mask.h entity.h component.h
	$(CC) -c -g -Wall system.c

run: main
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) $(LIBRARY)
