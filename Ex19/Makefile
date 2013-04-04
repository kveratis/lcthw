CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
LIB_SOURCES=object.c engine.c
SOURCES=ex19.c
LIBS=$(LIB_SOURCES:.c=.o)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex19

all: clean link
	rm -f *.o

library: $(LIB_SOURCES)
	scan-build $(CC) $(CFLAGS) $(LIB_SOURCES)

build: library $(SOURCES)
	scan-build $(CC) $(CFLAGS) $(SOURCES)

link: build $(LIBS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(EXECUTABLE)

clean:
	rm -f *.o *.log $(EXECUTABLE)
