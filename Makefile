# all:
# 	g++ main.cpp -o main
# 	./main

all:
	g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
