CC=clang
CFLAGS=-c -Werror -Wall -g -fshow-source-location
LDFLAGS=
LIB_SOURCES=ex22.c
SOURCES=ex22_main.c
LIBS=$(LIB_SOURCES:.c=.o)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ex22

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
