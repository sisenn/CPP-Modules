 #ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

    protected:

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

        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        std::string getName() const;

        virtual ~ClapTrap();
};

#endif