#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "contact.hpp"
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class PhoneBook 
{
    private:

        Contact contacts[8];
        int id;
        int max;

    public:

        PhoneBook();
        void addContact(void);
        void searchContact(void);
        
};

#endif