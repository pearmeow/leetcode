default: compile

run: compile
	./$(args)

compile:
	g++ -std=c++17 -pedantic -Wall -Wextra -Werror -o $(args).exe -g $(args).cpp

clean:
	rm *.exe
