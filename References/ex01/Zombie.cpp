#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
    std::cout << this->name << " was destroyed!" << std::endl;
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}