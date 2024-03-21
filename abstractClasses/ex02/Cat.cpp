#include "Cat.hpp" 

Cat::Cat() { 
        this->type = "Cat";
	    this->brain = new Brain();
        std::cout << "A new cat of type " << type << " is born. It has a brain!" << std::endl;
}

Cat::Cat(const Cat& other) {

    std::cout << "Copy Constructor: Creating a copy of a Cat with BRAIN." << std::endl;
     this->brain = new Brain();
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {

    if (this != &other) {
        this->type = other.type;
        delete this->brain;
	    this->brain = new Brain(*other.brain);
        std::cout << "Assigning a cat with BRAIN." << std::endl;
    }
    return *this;
}

Cat::~Cat() {

    std::cout << "Destroying a cat wit BRAIN." << std::endl;
    delete brain;
}

void Cat::makeSound() const {

    std::cout << "Meow Meow for your BRAIN!" << std::endl;
}