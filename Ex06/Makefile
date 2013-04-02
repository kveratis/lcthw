CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex6.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex6

all: clean validate
	rm -f *.o

build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

link: build $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

validate: link $(EXECUTABLE)
	valgrind --track-origins=yes ./$(EXECUTABLE) > validate.log

clean:
	rm -f *.o *.log $(EXECUTABLE)
