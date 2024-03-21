#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
# include "Brain.hpp"

class Animal {

    protected:

        std::string type;
    
    public:

        Animal();
        explicit Animal(const std::string& animalType);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        
        virtual void makeSound() const;
        
        std::string getType() const;
};

#endif