default: run

run: compile
	./$(num)

compile:
	g++ -std=c++11 -pedantic -Wall -Wextra -Werror -o $(num) -g $(num).cpp

clean:
	rm $(num)