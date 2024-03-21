#include "ScavTrap.hpp"

int main() 
{

    std::cout << std::endl;
    std::cout << "Example for ClapTrap: " << std::endl << std::endl;

    ClapTrap clapTrap("Tom");
    clapTrap.attack("Jerry");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(30);
    std::cout << "ClapTrap's HitPoints: " << clapTrap.getHitPoints() << std::endl;

    std::cout << std::endl;
    std::cout << "Example for ScavTrap: " << std::endl << std::endl;

    ScavTrap scavTrap("Mordekay");
    scavTrap.attack("Rigby");
    scavTrap.guardGate();
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(20);
    std::cout << "ScavTrap's HitPoints: " << scavTrap.getHitPoints() << std::endl;

    std::cout << std::endl;

    return 0;
}