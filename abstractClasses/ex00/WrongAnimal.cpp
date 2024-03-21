#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type( "WrongAnimal" ) {

    std::cout << "Default Constructor: Creating a Wrong Animal!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {

    std::cout <<  "Copy Constructor: Creating a copy of a Wrong Animal!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    
    if (this != &other) {
        this->type = other.type;
        std::cout << "Assigning a Wrong Animal." << std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destroying a Wrong Animal." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some Wrong Animal sounds." << std::endl;
}

std::string WrongAnimal::getType() const {
    return(this->type);
}