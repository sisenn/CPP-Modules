#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << name << " has been created successfully." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}