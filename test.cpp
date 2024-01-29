#include <unordered_map>
#include <iostream>

int main(int argc, char* argv[]) {
    int x = 10;
    int* y = &x;
    std::cout << *y << std::endl;
}

