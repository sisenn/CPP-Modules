#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

    this->EnergyPoints = 50;
    this->HitPoints = 100;
    this->name = "Gargamel";
    this->AttackDamage = 20;
    std::cout << "Default constructor called for ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    std::cout << "Copy constructor called for ScavTrap." << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.getName();
    }
    return(*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap named " << name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap named " << name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints -= 1;
    } 
    else 
    {
        std::cout << "ScavTrap " << name << " can't attack. No hit points or energy left." << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (HitPoints > 0)
        std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
    else
       std::cout << "ScavTrap " << getName() << " is already dead" << std::endl;
}