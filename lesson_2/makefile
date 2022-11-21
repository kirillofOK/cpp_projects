CC=g++
CFLAGS =-g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors

all: main.o create.o out.o functions.o 
	$(CC) -o lesson2 main.o create.o out.o functions.o 

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

create.o: create.cpp
	$(CC) $(CFLAGS) -c create.cpp

out.o: out.cpp
	$(CC) $(CFLAGS) -c out.cpp

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp

clean:
	rm -rf *.o lesson2