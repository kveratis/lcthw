CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex1.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex1

all: $(SOURCES) clean build
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

build:
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o $(EXECUTABLE)
