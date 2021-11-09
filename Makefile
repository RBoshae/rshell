COMPILE = g++
FLAGS = -std=c++11 -Wall -pedantic -Wsuggest-override

OBJS = ./bin/command.o ./bin/and.o ./bin/cd.o ./bin/or.o ./bin/statement.o ./bin/semicolon.o ./bin/parser.o ./bin/test.o

all: ./src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/rshell

./bin/command.o: ./src/command.h ./src/command.cpp
	$(COMPILE) $(FLAGS) -c ./src/command.cpp -o ./bin/command.o

./bin/and.o: ./src/command.h ./src/and.h ./src/and.cpp
	$(COMPILE) $(FLAGS) -c ./src/and.cpp -o ./bin/and.o

./bin/cd.o: ./src/command.h ./src/cd.h ./src/cd.cpp
	$(COMPILE) $(FLAGS) -c ./src/cd.cpp -o ./bin/cd.o

./bin/or.o: ./src/command.h ./src/or.h ./src/or.cpp
	$(COMPILE) $(FLAGS) -c ./src/or.cpp -o ./bin/or.o

./bin/statement.o: ./src/command.h ./src/statement.h ./src/statement.cpp
	$(COMPILE) $(FLAGS) -c ./src/statement.cpp -o ./bin/statement.o
	
./bin/semicolon.o: ./src/command.h ./src/semicolon.h ./src/semicolon.cpp
	$(COMPILE) $(FLAGS) -c ./src/semicolon.cpp -o ./bin/semicolon.o

./bin/parser.o: ./src/parser.h ./src/parser.h ./src/parser.cpp
	$(COMPILE) $(FLAGS) -c ./src/parser.cpp -o ./bin/parser.o

./bin/test.o: ./src/test.h ./src/test.h ./src/test.cpp
	$(COMPILE) $(FLAGS) -c ./src/test.cpp -o ./bin/test.o
clean:
	rm -rf ./bin/*
