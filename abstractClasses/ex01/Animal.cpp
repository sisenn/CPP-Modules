#include "Animal.hpp"
 
Animal::Animal() {

    this->type = "Animal";
    std::cout << "Default Constructor: Creating an " << type << std::endl;
}

Animal::Animal(const std::string& animalType) {
    
    std::cout << "Parameterized Constructor: Creating an Animal of type " << animalType << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Copy Constructor: Creating a copy of an Animal of type " << type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Copy Assignment Operator: Copying an Animal of type " << type << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor: Destroying an Animal of type " << type << std::endl;
}

void Animal::makeSound() const {
    std::cout << "This animal doesn't have a specific sound defined yet." << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}