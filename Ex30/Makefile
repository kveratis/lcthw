CC=clang
CFLAGS=-Wall -Wextra -fshow-source-location $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*/.c src/*.c)
TARGET_OBJECTS=ex30.o
LIB_OBJECTS=libex30.o
TARGET=bin/ex30
LIBRARY=bin/libex30.a
SO_TARGET=bin/libex30.so

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

# The target build
all: $(TARGET) $(LIBRARY) $(SO_TARGET) tests

debug: CFLAGS += -g -DNDEBUG
debug: all

$(LIBRARY): CFLAGS += -fPIC
$(LIBRARY): build 
	ar rcs $(LIBRARY) $(LIB_OBJECTS)
	ranlib $(LIBRARY)

$(SO_TARGET): build
	$(CC) -shared -o $(SO_TARGET) $(LIB_OBJECTS)

$(TARGET): $(SO_TARGET)
	$(CC) $(TARGET_OBJECTS) $(LIBS) -o $(TARGET)

build: $(SOURCES)  
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $(SOURCES)

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(LIBRARY)
tests: $(TESTS)
	sh ./tests/runtests.sh

# The Cleaner
clean:
	rm -rf build *.o $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

purge: clean
	rm -rf bin
