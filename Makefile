CC=gcc
EXECUTABLE=main
OBJECTS=mask.o

main: $(OBJECTS) main.c
	$(CC) -Wall -g -o $(EXECUTABLE) $(OBJECTS) main.c

mask.o: mask.c
	$(CC) -c -g -Wall mask.c

run: main
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
