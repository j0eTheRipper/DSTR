build/main: build/LinkedList.o build/Transaction.o main.cpp
	g++ build/LinkedList.o build/Transaction.o main.cpp -o build/main
	./build/main

build/LinkedList.o:
	g++ -c LinkedList/LinkedList.cpp -o build/LinkedList.o

build/Transaction.o: LinkedList/Node/Transaction.cpp
	g++ -c LinkedList/Node/Transaction.cpp -o build/Transaction.o
