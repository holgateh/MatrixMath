run: 
	cmd /K a.exe
compile: 
	g++ *.cpp
all:
	g++ *.cpp && cmd /K a.exe