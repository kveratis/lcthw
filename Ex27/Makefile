CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex27.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex27

all: clean validate
	rm -f *.o

build: $(SOURCES)
	scan-build $(CC) $(CFLAGS) $(SOURCES)

link: build $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

validate: link $(EXECUTABLE)
	valgrind --track-origins=yes --leak-check=full ./$(EXECUTABLE)
clean:
	rm -f *.o *.log $(EXECUTABLE)
