CC=g++
CFLAGS=-c -v -mtune=generic
SOURCES=main.cpp extra_functions.cpp functions.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

