#include "Zombie.hpp"

int main()
{
	Zombie *pointerZombie;
	int n = 3;

	pointerZombie = zombieHorde(n, "Steve");

	for(int i=0; i < n; i++) {
		pointerZombie[i].announce();
	}
	delete[] pointerZombie;
}