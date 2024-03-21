#include "Dog.hpp" 

Dog::Dog() {

    this->type = "Dog";
	this->brain = new Brain();
    std::cout << "A new dog of type " << type << " is born. It has a brain!" << std::endl;
}

Dog::Dog(const Dog& other) {
    
    std::cout << "Copy Constructor: Creating a copy of a Dog with BRAIN." << std::endl;
    this->brain = new Brain();
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {

    if (this != &other) {
        this->type = other.type;
        delete this->brain;
	    this->brain = new Brain(*other.brain);
        std::cout << "Assigning a dog with BRAIN." << std::endl;
    }
    return *this;
}

Dog::~Dog() {

    std::cout << "Destroying a dog with BRAIN." << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof for your BRAIN!" << std::endl;
}