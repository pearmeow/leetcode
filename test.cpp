#include <unordered_map>
#include <iostream>

int main(int argc, char* argv[]) {
    std::unordered_map<int, int> test;
    test[0] = 90;
    std::cout << test[0] << std::endl;
    std::cout << test[1] << std::endl;
    std::cout << test[1] << std::endl;
    return 0;
}