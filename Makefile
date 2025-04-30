build/main: build/LinkedList.o build/Transaction.o build/Node.o build/Review.o main.cpp
	g++ build/LinkedList.o build/Transaction.o build/Node.o build/Review.o main.cpp -o build/main
	./build/main

build/LinkedList.o: LinkedList/LinkedList.cpp
	g++ -c LinkedList/LinkedList.cpp -o build/LinkedList.o

build/Node.o: LinkedList/Node/Node.cpp
	g++ -c LinkedList/Node/Node.cpp -o build/Node.o

build/Transaction.o: LinkedList/Node/Transaction.cpp
	g++ -c LinkedList/Node/Transaction.cpp -o build/Transaction.o

build/Review.o: LinkedList/Node/Review.cpp
	g++ -c LinkedList/Node/Review.cpp -o build/Review.o
