#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Contact
{

    private:

        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
    
        Contact();
        void set_contact(std::string firstName, std::string lastName, std::string nickname, std::string phonenumber, std::string darkestSecret);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
};

#endif