#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {

    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    name = "Gargamel";
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
    std::cout << "Copy constructor called for FragTrap." << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.getName();
    }
    return(*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;

    std::cout << "FragTrap constructor called." << std::endl;
}

void FragTrap::highFivesGuys() {
    if (HitPoints > 0)
        std::cout << "FragTrap " << getName() << " requests a high five!" << std::endl;
    else
        std::cout << "FragTrap " << getName() << " is already dead" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap named " << getName() << " is destroyed!" << std::endl;
}
