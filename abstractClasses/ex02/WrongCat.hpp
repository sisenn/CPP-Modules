#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:

        WrongCat();
        explicit WrongCat(const std::string& animalType);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();
        
        void makeSound() const;

		std::string getType() const;
};

#endif