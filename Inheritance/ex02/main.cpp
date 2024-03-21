#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{

    std::cout << std::endl;
    ClapTrap clapTrap("Clappy");
    
    clapTrap.attack("Target1");
    clapTrap.takeDamage(20);
    clapTrap.beRepaired(15);
    
    std::cout << std::endl;
    FragTrap fragTrap("Fraggy");

    fragTrap.attack("Target2");
    fragTrap.takeDamage(30);
    fragTrap.beRepaired(25);

    std::cout << std::endl;
    fragTrap.highFivesGuys();
    
    return 0;
}
