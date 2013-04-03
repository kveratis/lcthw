CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex17.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex17

all: clean validate
	rm -f *.o

build: $(SOURCES)
	scan-build $(CC) $(CFLAGS) $(SOURCES)

link: build $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

setup: link $(EXECUTABLE)
	./db-setup.sh

validate: setup $(EXECUTABLE)
	valgrind --track-origins=yes --leak-check=full ./$(EXECUTABLE) test.dat g 2
clean:
	rm -f *.o *.log $(EXECUTABLE)
