CC=g++
CFLAGS =-g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors

all: main.o create.o functions.o 
	$(CC) -o lesson3 main.o create.o functions.o 

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

create.o: create.cpp
	$(CC) $(CFLAGS) -c create.cpp

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp

clean:
	rm -rf *.o lesson3