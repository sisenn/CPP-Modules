#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "--------------------------------" << std::endl;

    std::cout << "META Type: " << meta->getType() << " " << std::endl;
    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl; 
    std::cout << "--------------------------------" << std::endl;

    meta->makeSound();
    i->makeSound();
    j->makeSound();
    std::cout << "--------------------------------" << std::endl;
    
    delete  j;
    delete  i;
    delete  meta;
    std::cout << "--------------------------------" << std::endl;

    const WrongAnimal *wrong = new WrongCat();
    std::cout << "--------------------------------" << std::endl;

    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
    std::cout << "--------------------------------" << std::endl;

    wrong->makeSound();
    std::cout << "--------------------------------" << std::endl;

    delete  wrong;

    return 0;
}