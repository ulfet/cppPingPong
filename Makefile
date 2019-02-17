all:
	g++ -c hello.cpp 
	g++ hello.o -o hello -lsfml-graphics -lsfml-window -lsfml-system
run:
	g++ -c hello.cpp 
	g++ hello.o -o hello -lsfml-graphics -lsfml-window -lsfml-system
	@./hello

