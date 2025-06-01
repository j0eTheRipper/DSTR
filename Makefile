build/main: build/LinkedList.o build/Node.o build/Array.o build/Player.o build/LinkedListPriorityQueue.o build/SingleLinkNode.o main.cpp build
	g++ build/*.o main.cpp -o build/main -g

build/LinkedList.o: DataStructures/LinkedList/LinkedList.cpp
	g++ -c DataStructures/LinkedList/LinkedList.cpp -o build/LinkedList.o -g

build/Node.o: DataStructures/LinkedList/Node/Node.cpp
	g++ -c DataStructures/LinkedList/Node/Node.cpp -o build/Node.o -g

build/Array.o: DataStructures/Array/Array.cpp
	g++ -c DataStructures/Array/Array.cpp -o build/Array.o -g

build/Player.o: DataStructures/LinkedList/PriorityQueue/Player.cpp
	g++ -c DataStructures/LinkedList/PriorityQueue/Player.cpp -o build/Player.o -g

build/LinkedListPriorityQueue.o: DataStructures/LinkedList/PriorityQueue/LinkedListPriorityQueue.cpp
	g++ -c DataStructures/LinkedList/PriorityQueue/LinkedListPriorityQueue.cpp -o build/LinkedListPriorityQueue.o -g

build/SingleLinkNode.o: DataStructures/LinkedList/Node/SingleLinkNode.cpp
	g++ -c DataStructures/LinkedList/Node/SingleLinkNode.cpp -o build/SingleLinkNode.o -g

build:
	mkdir build

