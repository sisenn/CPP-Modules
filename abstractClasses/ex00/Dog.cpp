#include "Dog.hpp" 

Dog::Dog() : Animal () {

    this->type = "Dog";
    std::cout << "Default Constructor: Creating a Dog!" << std::endl;
}

Dog::Dog(const Dog& other) {
    
    *this = other;
    std::cout << "Copy Constructor: Creating a copy of a Dog." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    
    if (this != &other) {
        type = other.type;
        std::cout << "Copy assignment: Assigning a dog." << std::endl;
    }
    return *this;
}

Dog::~Dog() {

    std::cout << "Destroying a dog." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}