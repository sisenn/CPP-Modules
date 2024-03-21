#include "iter.hpp"

int main() {
    
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(int);
    std::cout << "Iterating over int array: ";
    iter(intArray, intArraySize, print<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);
    std::cout << "Iterating over double array: ";
    iter(doubleArray, doubleArraySize, print<double>);
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = sizeof(charArray) / sizeof(char);
    std::cout << "Iterating over char array: ";
    iter(charArray, charArraySize, print<char>);
    std::cout << std::endl;

    return 0;
}
