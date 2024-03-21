#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "Test 1: Creation and destruction of Dog and Cat objects." << std::endl;
    std::cout << "\n------------------------------------------------------------------\n" << std::endl;
     const Animal* j = new Dog();
     const Animal* i = new Cat();

     delete i;
     delete j;

     std::cout << "\n------------------------------------------------------------------\n" << std::endl;

     std::cout << "Test 2: Copying and destroying the Dog object." << std::endl;
    std::cout << "\n------------------------------------------------------------------\n" << std::endl;
     Dog basic;
     {
         Dog tmp = basic;
     }

     std::cout << "\n------------------------------------------------------------------\n" << std::endl;

     std::cout << "Test 3: Creating and destroying Dog and Cat objects in an array." << std::endl;
     std::cout << "\n------------------------------------------------------------------\n" << std::endl;
     const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
     for (int i = 0; i < 4; i++) {
         delete animals[i];
     }

     std::cout << "\n------------------------------------------------------------------\n" << std::endl;

     std::cout << "Test 4: Copying and destroying the WrongCat object." << std::endl;
     std::cout << "\n------------------------------------------------------------------\n" << std::endl;
     WrongCat wrongBasic;
     {
         WrongCat tmp = wrongBasic;
     }

     std::cout << "\n------------------------------------------------------------------\n" << std::endl;

}
