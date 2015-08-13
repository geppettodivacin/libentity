CC=gcc
EXECUTABLE=main
OBJECTS=mask.o entity.o component.o world.o

main: $(OBJECTS) main.c
	$(CC) -Wall -g -o $(EXECUTABLE) $(OBJECTS) main.c

mask.o: mask.c
	$(CC) -c -g -Wall mask.c

entity.o: entity.c
	$(CC) -c -g -Wall entity.c

component.o: component.c
	$(CC) -c -g -Wall component.c

world.o: world.c
	$(CC) -c -g -Wall world.c

run: main
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
