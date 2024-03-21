#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


int main() {
    try {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("John");
        PresidentialPardonForm pardon("Alice");

        std::cout << bob << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);

    } catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
