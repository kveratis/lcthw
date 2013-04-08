CC=clang
PREFIX?=/usr/local
CFLAGS=-c -Werror -Wall -g -fshow-source-location -I${PREFIX}/apr/include/apr-1 -I${PREFIX}/apr/include/apr-util-1 -D_LARGEFILE64_SOURCE=1
LDFLAGS=-L${PREFIX}/apr/lib -lapr-1 -pthread -laprutil-1
SOURCES=db.c shell.c commands.c
BSTR_SRC=bstrlib.c
OBJECTS=$(SOURCES:.c=.o)
BSTR_OBJ=$(BSTR_SRC:.c=.o)
EXECUTABLE=devpkg

all: devpkg

devpkg: link $(OBJECTS) $(BSTR_OBJ)

build: $(SOURCES)
	scan-build $(CC) $(CFLAGS) $(SOURCES)

bstr: $(BSTR_SRC)
	$(CC) $(CFLAGS) -o $(BSTR_OBJ) $(BSTR_SRC)

link: build bstr
	$(CC) $(LDFLAGS) $(OBJECTS) $(BSTR_OBJ) -o $(EXECUTABLE)

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install devpkg $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
	rm -rf *.dSYM

