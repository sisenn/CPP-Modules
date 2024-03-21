#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Gargamel") {
     std::cout << "ClapTrap named " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
     std::cout << "ClapTrap named " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this=other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.getName();
    }
    return(*this);
}

void ClapTrap::attack(const std::string& target) {
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints -= 1;
    } 
    else 
    {
        std::cout << "ClapTrap " << name << " can't attack. No hit points or energy left." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (HitPoints > 0) 
    {
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        HitPoints = std::max(0, HitPoints - static_cast<int>(amount));
    } 
    else 
    {
        std::cout << "ClapTrap " << name << " is already out of hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (HitPoints > 0 && EnergyPoints > 0) 
    {
        std::cout << "ClapTrap " << name << " is repaired, gaining " << amount << " hit points!" << std::endl;
        HitPoints += amount;
        EnergyPoints -= 1;
    } 
    else 
    {
        std::cout << "ClapTrap " << name << " can't be repaired. No hit points or energy left." << std::endl;
    }
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap named " << name << " is destroyed!" << std::endl; 
}

int ClapTrap::getHitPoints() const {
    return HitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return EnergyPoints;
}

int ClapTrap::getAttackDamage() const {
    return AttackDamage;
}

std::string ClapTrap::getName() const{
    return name;
}
