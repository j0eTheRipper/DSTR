build/main: build/LinkedList.o build/Node.o build/Array.o main.cpp build
	g++ build/LinkedList.o build/Node.o build/Array.o main.cpp -o build/main -g

build/LinkedList.o: DataStructures/LinkedList/LinkedList.cpp
	g++ -c DataStructures/LinkedList/LinkedList.cpp -o build/LinkedList.o -g

build/Node.o: DataStructures/LinkedList/Node/Node.cpp
	g++ -c DataStructures/LinkedList/Node/Node.cpp -o build/Node.o -g

build/Array.o: DataStructures/Array/Array.cpp
	g++ -c DataStructures/Array/Array.cpp -o build/Array.o -g

build:
	mkdir build

