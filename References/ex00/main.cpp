#include "Zombie.hpp"

int main(void)
{
    std::cout << std::endl;

	Zombie *heapZombie;
    heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    delete heapZombie;

    std::cout << std::endl;
    randomChump("RandomChumpZombie");
    std::cout << std::endl;
    
	return (0);
}