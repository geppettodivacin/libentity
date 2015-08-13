CC=gcc
EXECUTABLE=main
OBJECTS=mask.o

main: $(OBJECTS) main.c
	$(CC) -Wall -o $(EXECUTABLE) $(OBJECTS) main.c

mask.o: mask.c
	$(CC) -c -Wall mask.c

run: main
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
