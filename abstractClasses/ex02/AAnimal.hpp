#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
# include "Brain.hpp"

class AAnimal {

    protected:

        std::string type;
    
    public:

        AAnimal();
        explicit AAnimal(const std::string& animalType);
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();
        
        virtual void makeSound() const = 0;
        
        std::string getType() const;
};

#endif