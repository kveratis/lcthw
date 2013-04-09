CC=clang
CFLAGS=-c -Wall -Wextra -Werror -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCE_DIR=src/
BUILD_DIR=build/
TARGET_DIR=bin/
TARGET_SOURCES=$(SOURCE_DIR)ex29.c
LIB_SOURCES=$(SOURCE_DIR)libex29.c
TARGET_OBJECTS=$(BUILD_DIR)ex29.o
LIB_OBJECTS=$(BUILD)libex29.o
TARGET=$(TARGET_DIR)ex29
LIBRARY=$(TARGET_DIR)libex29.a
SO_TARGET=$(TARGET_DIR)libex29.so

# The target build
all: $(TARGET) $(SO_TARGET) tests
	
dev: CFLAGS=-g -Wall -Wextra -Werror -fshow-source-location $(OPTFLAGS)
dev: all

$(LIBRARY): CFLAGS += -fPIC
$(LIBRARY): build
	$(CC) $(CFLAGS) $(LIB_SOURCES) -o $(LIB_OBJECTS)
	ar rcs $(LIBRARY) $(LIB_OBJECTS)
	ranlib $(LIBRARY)

$(SO_TARGET): $(LIBRARY)
	$(CC) -shared -o $(SO_TARGET) $(LIB_OBJECTS)

$(TARGET): $(SO_TARGET)
	$(CC) $(CFLAGS) $(TARGET_SOURCES) -o $(TARGET_OBJECTS)
	$(CC) $(TARGET_OBJECTS) $(LIBS) -o $(TARGET)

build: $(LIB_SOURCES)
	@mkdir -p build
	@mkdir -p bin

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`
