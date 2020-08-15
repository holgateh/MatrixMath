cc=g++
cflags=-std=c++17

compile: 
		$(cc) $(cflags) *.cpp
run: 
	./a.out
all:
	compile run	
