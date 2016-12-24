compile: build/main.o build/Board.o
	g++ -O3 build/main.o build/Board.o -o bin/main

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o

build/Board.o: src/Board.cpp
	g++ -c src/Board.cpp -o build/Board.o

clean:
	rm build/*
	rm bin/*

run:
	./bin/main
