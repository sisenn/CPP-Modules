#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {
    std::cout << name << " was created." << std::endl;
}

HumanB::~HumanB() {
    std::cout << name << " was destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    if(!weapon)
        std::cout << name << " cannot attack without any weapon!" << std::endl;
    else
        std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}