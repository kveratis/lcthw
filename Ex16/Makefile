CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
SOURCES=ex16.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex16

all: clean validate
	rm -f *.o

build: $(SOURCES)
	scan-build $(CC) $(CFLAGS) $(SOURCES)

link: build $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

validate: link $(EXECUTABLE)
	valgrind --track-origins=yes ./$(EXECUTABLE) > validate.log

clean:
	rm -f *.o *.log $(EXECUTABLE)
