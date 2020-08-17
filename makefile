cc=g++
cflags=-std=c++17
srcPATH=src/
compile: 
		$(cc) $(cflags) $(srcPATH)*.cpp
run: 
	./a.out
all:
	compile run	
