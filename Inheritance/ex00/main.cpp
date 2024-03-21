#include "ClapTrap.hpp"

int main() 
{
    ClapTrap claptrap("Tom");
    claptrap.attack("Jerry");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    return 0;
}