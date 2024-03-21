#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default Constructor: Creating a Brain with default ideas." << std::endl;
    for (int i = 0; i < 100; i++)
		this->Ideas[i] = "";
}

Brain::~Brain() {
    std::cout << "Destructor: Destroying a Brain." << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy Constructor: Creating a copy of a Brain." << std::endl;
    for (int i = 0; i < 100; i++)
		this->Ideas[i] = other.Ideas[i];
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Copy Assignment Operator: Copying a Brain." << std::endl;
    if (this != &other) {
        for (int j = 0; j < 100; j++) {
            this->Ideas[j] = other.Ideas[j];
        }
    }
    return *this;
}

std::string	*	Brain::getIdeas(void){
	return (this->Ideas);
}

std::string	Brain::getIdea(int j) const{
	return this->Ideas[j];
}
