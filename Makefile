all:
	g++ -std=c++17 src/*.cpp -o main -Iincludes -lsfml-graphics -lsfml-window -lsfml-system
	./main
