#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"

class Dog : public AAnimal {

    private:

        Brain *brain;
        
    public:

        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound() const;
};

#endif