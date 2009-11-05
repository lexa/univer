HEADERS=filter.hpp
OBJ=main.o filter.o

all:$(OBJ)
		g++ $(OBJ)  -o main -ansi -W  -pedantic -Wall -Wextra  -O0 -ggdb3 
