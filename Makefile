all:
	g++ -c hello.cpp 
	g++ hello.o -o hello -lsfml-graphics -lsfml-window -lsfml-system
run:
	@./hello

