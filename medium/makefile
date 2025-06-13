default: run

run: compile
	./$(ARGS)

compile:
	g++ -std=c++17 -pedantic -Wall -Wextra -Werror -o $(ARGS).exe -g $(ARGS).cpp

clean:
	rm $(ARGS)
