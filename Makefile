COMPILE = g++
FLAGS =-Wall -Werror -ansi -pedantic

OBJS = ./bin/Argument.o ./bin/And.o ./bin/Or.o ./bin/Statement.o

all: ./src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/rshell

./bin/Argument.o: ./src/Argument.h ./src/Argument.cpp
	$(COMPILE) $(FLAGS) -c ./src/Argument.cpp -o ./bin/Argument.o

./bin/And.o: ./src/Argument.h ./src/And.h ./src/And.cpp
	$(COMPILE) $(FLAGS) -c ./src/And.cpp -o ./bin/And.o

./bin/Or.o: ./src/Argument.h ./src/Or.h ./src/Or.cpp
	$(COMPILE) $(FLAGS) -c ./src/Or.cpp -o ./bin/Or.o

./bin/Statement.o: ./src/Argument.h ./src/Statement.h ./src/Statement.cpp
	$(COMPILE) $(FLAGS) -c ./src/Statement.cpp -o ./bin/Statement.o
clean:
	rm -rf ./bin/
