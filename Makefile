build/main: build/LinkedList.o build/Node.o
	g++ build/LinkedList.o build/Node.o main.cpp -o build/main
	./build/main

build/LinkedList.o:
	g++ -c LinkedList/LinkedList.cpp -o build/LinkedList.o

build/Node.o:
	g++ -c LinkedList/Node/Node.cpp -o build/Node.o
