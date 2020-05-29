all:
	g++ -std=c++17 *.cpp && ./a.out 
run: 
	./a.out
compile: 
	g++ *.cpp
