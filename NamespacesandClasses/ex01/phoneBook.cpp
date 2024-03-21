#include "phoneBook.hpp"

PhoneBook:: PhoneBook(){

    this->id = 0;
    this->max = 0;
}

int validNumber(std::string nbr){
    int i=0;
    while(nbr[i])
    {
        if(!(nbr[i] >= '0' && nbr[i] <= '9'))
            return 0;
        i++;
    }
    return 1;
}

int isAlpha(std::string name) 
{
    int i=0;
    while(name[i])
    {
        if(!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
            return 0;
        i++;
    }
    return 1;
}

int stringToInt(const std::string& str) {
    if(str.length() > 1)
    {
        return -1;
    }
    return std::stoi(str);
}

void PhoneBook::addContact(void) {
    
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

        while(1)
        {
            fName:
            std::cout << "First Name: ";
            std::getline(std::cin, firstName);
            if (std::cin.fail())
            {
                std::cin.eof();
                std::cout << "Exiting program" << std::endl;
                return ;
            }
            if(firstName.empty()) {
                std::cerr << "First name cannot be empty! Please try again." << std::endl;
                goto fName;
            }
            if(!(isAlpha(firstName))) {
                std::cerr << "Wrong entrance ! Please try again carefully." << std::endl;
                goto fName;
            }
            lName:
            std::cout << "Last Name: ";
            std::getline(std::cin, lastName);
            if (std::cin.fail())
            {
                std::cin.eof();
                std::cout << "Exiting program" << std::endl;
                return ;
            }
            if(lastName.empty()) {
                std::cerr << "Last name cannot be empty! Please try again." << std::endl;
                goto lName;
            }
            if(!(isAlpha(lastName)))
            {
                std::cerr << "Wrong entrance ! Please try again carefully." << std::endl;
                goto lName;
            }
            Nick:
            std::cout << "Nickname: ";
            std::getline(std::cin, nickname);
            if (std::cin.fail())
            {
                std::cin.eof();
                std::cout << "Exiting program" << std::endl;
                return ;
            }
            if(nickname.empty()) {
                std::cerr << "Nickname cannot be empty! Please try again." << std::endl;
                goto Nick;
            }
            phoneNbr:
            std::cout << "Phone number: ";
            std::getline(std::cin, phoneNumber);
            if (std::cin.fail())
            {
                std::cin.eof();
                std::cout << "Exiting program" << std::endl;
                return ;
            }
            if(phoneNumber.empty()) {
                std::cerr << "Phone number cannot be empty! Please try again." << std::endl;
                goto phoneNbr;
            }
            if(!(validNumber(phoneNumber))) {
                std::cerr << "Wrong entrance ! Please try again carefully." << std::endl;
                goto phoneNbr;
            }
            Darkest:
            std::cout << "Darkest Secret: ";
            std::getline(std::cin, darkestSecret);
            if (std::cin.fail())
            {
                std::cin.eof();
                std::cout << "Exiting program" << std::endl;
                return ;
            }
            if(darkestSecret.empty()) {
                std::cerr << "Darkest secret cannot be empty! Please try again." << std::endl;
                goto Darkest;
            }
            this->contacts[this->id++].set_contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            if(this->id == 8)
                this->id = 0;
            if(this->max<8)
                this->max++;
                break;
        }
}

std::string textStructuring(std::string str) {
    if(str.size() >= 10)
        return(str.substr(0,9) + ".");
    return(str);
}

void PhoneBook::searchContact(void) 
{
    int index;
    std::string input;
    
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│" << std::setw(10) << std::right << "index";
    std::cout << "│" << std::setw(10) << std::right << "first name";
    std::cout << "│" << std::setw(10) << std::right << "last name";
    std::cout << "│" << std::setw(10) << std::right << "nickname" << "│" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
    for (int i=0; i < this->max; i++)
    {
        Contact contact;
        contact = this->contacts[i];
        std::cout << "|" << std::setw(10) << i + 1;
        std::cout << "|" << std::setw(10) << textStructuring(contact.getFirstName());
        std::cout << "|" << std::setw(10) << textStructuring(contact.getLastName());
        std::cout << "|" << std::setw(10) << textStructuring(contact.getNickname()) << "|" << std::endl;
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
    while(1)
    {
        std::cout << "Enter the index number of the data you want to view:" << std::endl;
        std::cout << ">";
        if (std::cin >> input)
		{
            if (!(validNumber(input)))
                continue;
            std::cin.ignore(1,'\n');
            index = stringToInt(input);
            if ((index >0 && index <=8) && index <= this->max)
			{

                std::cout << std::endl;
                std::cout << "First name - " << this->contacts[index-1].getFirstName() << std::endl;
                std::cout << "Last name - " << this->contacts[index-1].getLastName() << std::endl;
                std::cout << "Nickname - " << this->contacts[index-1].getNickname() << std::endl;
                std::cout << "Phone number - " << this->contacts[index-1].getPhoneNumber() << std::endl;
                std::cout << "Darkest secret - " << this->contacts[index-1].getDarkestSecret() << std::endl;
                std::cout << std::endl;
				break;
			}
			else
				std::cout << "Invalid input. Please enter a valid index." << std::endl;
		}
		else {
            std::cout << "Invalid input. Please enter a valid index." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }
    }
}