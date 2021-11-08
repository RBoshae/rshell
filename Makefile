COMPILE = g++
FLAGS = -std=c++17 -Wall -Werror -ansi -pedantic

OBJS = ./bin/command.o ./bin/And.o ./bin/Cd.o ./bin/Or.o ./bin/Statement.o ./bin/Semicolon.o ./bin/Parser.o ./bin/Test.o

all: ./src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/rshell

./bin/command.o: ./src/command.h ./src/command.cpp
	$(COMPILE) $(FLAGS) -c ./src/command.cpp -o ./bin/command.o

./bin/And.o: ./src/command.h ./src/And.h ./src/And.cpp
	$(COMPILE) $(FLAGS) -c ./src/And.cpp -o ./bin/And.o

./bin/Cd.o: ./src/command.h ./src/Cd.h ./src/Cd.cpp
	$(COMPILE) $(FLAGS) -c ./src/Cd.cpp -o ./bin/Cd.o

./bin/Or.o: ./src/command.h ./src/Or.h ./src/Or.cpp
	$(COMPILE) $(FLAGS) -c ./src/Or.cpp -o ./bin/Or.o

./bin/Statement.o: ./src/command.h ./src/Statement.h ./src/Statement.cpp
	$(COMPILE) $(FLAGS) -c ./src/Statement.cpp -o ./bin/Statement.o
	
./bin/Semicolon.o: ./src/command.h ./src/Semicolon.h ./src/Semicolon.cpp
	$(COMPILE) $(FLAGS) -c ./src/Semicolon.cpp -o ./bin/Semicolon.o

./bin/Parser.o: ./src/Parser.h ./src/Parser.h ./src/Parser.cpp
	$(COMPILE) $(FLAGS) -c ./src/Parser.cpp -o ./bin/Parser.o

./bin/Test.o: ./src/Test.h ./src/Test.h ./src/Test.cpp
	$(COMPILE) $(FLAGS) -c ./src/Test.cpp -o ./bin/Test.o
clean:
	rm -rf ./bin/*
