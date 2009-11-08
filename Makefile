HEADERS=filter.hpp
OBJ=main.o filter.o
CXXFLAGS=-ggdb3 -ansi -W  -pedantic -Wall -Wextra

all:$(OBJ)
		g++ $(OBJ)  -o main  $(CXXFLAGS) 
