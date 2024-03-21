#include "phoneBook.hpp"

void introduction(void)
{
    std::cout << std::endl;
    std::cout << MAGENTA << "Welcome To My Awesome Phonebook" << std::endl;
    std::cout << YELLOW << "-------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << WHITE << "Here are the commands you can use:" << std::endl;
    std::cout << std::endl;
    std::cout << WHITE << "ADD      --------->   Register a new contact" << std::endl;
    std::cout << WHITE << "SEARCH   --------->   View a specific person" << std::endl;
    std::cout << WHITE << "EXIT     --------->   The program closes and the contacts are lost forever!" << std::endl;
    std::cout << std::endl;
    std::cout << YELLOW << "-------------------------------" << std::endl;
    std::cout << RESET << std::endl;
}

int main(void)
{ 
    PhoneBook phoneBook1;
    std::string input;

    introduction();

    while(1)
    {
        std::cout << "Please choose a command: ADD | SEARCH | EXIT " << std::endl;
        std::cout << ">";
        std::getline(std::cin, input);
        if (std::cin.fail())
        {
            std::cin.eof(); 
           std::cout << "Exiting program" << std::endl;
            return 0;
        }
        else if(!(input.compare("")))
        {
            std::cout << "You should enter a command!" << std::endl;
            continue;
        }
        else if(!(input.compare("ADD")))
            phoneBook1.addContact();
        else if(!(input.compare("SEARCH")))
            phoneBook1.searchContact();
        else if(!(input.compare("EXIT")))
        {
            std::cout << "Exiting program" << std::endl;
            return 0;
        }
        else 
            std::cerr << "Wrong choice! Please try again." << std::endl;
    }
}