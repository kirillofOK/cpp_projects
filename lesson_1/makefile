CC=g++
CFLAGS =-g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors

all: epsilon.o main.o progression.o exp.o
	$(CC) -o lesson1 main.o progression.o exp.o epsilon.o 

epsilon.o: epsilon.cpp
	$(CC) $(CFLAGS) -c epsilon.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

progression.o: progression.cpp
	$(CC) $(CFLAGS) -c progression.cpp

exp.o: exp.cpp
	$(CC) $(CFLAGS) -c exp.cpp

clean:
	rm -rf *.o epsilon
