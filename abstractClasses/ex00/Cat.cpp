#include "Cat.hpp" 

Cat::Cat() : Animal() {

    this->type = "Cat";
    std::cout << "Default Constructor: Creating a Cat!" << std::endl;
}

Cat::Cat (const Cat& other) {

    *this = other;
    std::cout << "Copy Constructor: Creating a copy of a Cat." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {

    if (this != &other) {
        type = other.type;
        std::cout << "Assigning a cat." << std::endl;
    }
    return *this;
}

Cat::~Cat() {

    std::cout << "Destroying a cat." << std::endl;
}

void Cat::makeSound() const {

    std::cout << "Meow! Meow!" << std::endl;
}