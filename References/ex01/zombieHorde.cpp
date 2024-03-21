#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

    Zombie *pointerZombie = new Zombie[N];

    for (int i=0; i < N; i++) {
        pointerZombie[i] = Zombie(name);
    }
    return (pointerZombie);
}
