CC=clang
CFLAGS=-c -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex4.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex4

all: $(SOURCES) clean build
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

build:
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o $(EXECUTABLE)
