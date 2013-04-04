CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex20.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex20

all: clean link
	rm -f *.o

build: $(SOURCES)
	scan-build $(CC) $(CFLAGS) $(SOURCES)

link: build $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

clean:
	rm -f *.o *.log $(EXECUTABLE)
