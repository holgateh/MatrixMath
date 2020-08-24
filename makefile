cc=g++
cflags=-std=c++17 -pthread
srcPATH=src/
compile: 
		$(cc) $(cflags) $(srcPATH)*.cpp
run: 
	./a.out
all:
	compile run	
