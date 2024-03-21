#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {

    this->type = "WrongCat";
    std::cout << "Default Constructor: Creating a Wrong Cat!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {

    *this = other;
    std::cout << "Copy Constructor: Creating a copy of a Wrong Cat." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Copy assignment: Assigning a Wrong Cat." << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destroying a Wrong Cat." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow! Meow!" << std::endl;
}

std::string WrongCat::getType() const {

    return(this->type);
}