#include "contact.hpp"

Contact::Contact() {
    
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}

void Contact::set_contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
    return firstName;
}

std::string Contact::getLastName() {
    return lastName;
}

std::string Contact::getNickname() {
    return nickname;
}

std::string Contact::getPhoneNumber() {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() {
    return darkestSecret;
}
