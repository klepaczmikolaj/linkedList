#autor: Mikołaj Klepacz
#projekt 2

CC = g++

all: project2 clean

project2: main.o DoublyLinkedList.o Tests.o
	$(CC) main.o DoublyLinkedList.o Tests.o -o project2

main.o: main.cpp
	$(CC) -c main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp
	$(CC) -c DoublyLinkedList.cpp

Tests.o: Tests.cpp
	$(CC) -c Tests.cpp
	
clean:
	rm -f *o project2
