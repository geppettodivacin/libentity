CC=gcc
EXECUTABLE=main

main: main.c
	$(CC) main.c -o $(EXECUTABLE)

run: main
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)
