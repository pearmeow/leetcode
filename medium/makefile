default: run

run: compile
	./$(ARGS)

compile:
	g++ -std=c++11 -pedantic -Wall -Wextra -Werror -o $(ARGS) -g $(ARGS).cpp

clean:
	rm $(ARGS)