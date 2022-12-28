CC=g++
CFLAGS =-g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors
all: main.o functions.o extra_functions.o
	$(CC) -o lesson4 main.o extra_functions.o functions.o 

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp

extra_functions.o: extra_functions.cpp
	$(CC) $(CFLAGS) -c extra_functions.cpp

clean:
	rm -rf *.o lesson4

