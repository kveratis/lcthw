CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex3.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex3

all: $(SOURCES) clean build
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

build:
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o $(EXECUTABLE)
