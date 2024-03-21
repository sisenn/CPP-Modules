#include "WrongAnimal.hpp"
#include "AAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

		AAnimal *animal = new Dog();

		animal->makeSound();

		delete animal;

}