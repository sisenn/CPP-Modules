#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

    private:

        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;

    public:

        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        ~ClapTrap();

        int getHitPoint(void) const;
        int	getEnergyPoint(void) const;
		int getAttackPoint (void) const;
		std::string getName(void) const;
};

#endif