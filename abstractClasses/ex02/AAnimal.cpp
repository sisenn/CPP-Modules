#include "AAnimal.hpp"
 
AAnimal::AAnimal() {

    this->type = "AAnimal";
    std::cout << "Default Constructor: Creating an " << type << std::endl;
}

AAnimal::AAnimal(const std::string& animalType) {
    
    std::cout << "Parameterized Constructor: Creating an AAnimal of type " << animalType << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "Copy Constructor: Creating a copy of an AAnimal of type " << type << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Copy Assignment Operator: Copying an AAnimal of type " << type << std::endl;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Destructor: Destroying an AAnimal of type " << type << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "This animal doesn't have a specific sound defined yet." << std::endl;
}

std::string AAnimal::getType() const {
    return (this->type);
}