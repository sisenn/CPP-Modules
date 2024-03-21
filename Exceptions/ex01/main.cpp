#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        Form taxForm("Tax Form", 40, 30);
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);

        std::cout << taxForm << std::endl;

        Bureaucrat alice("Alice", 20);
        alice.signForm(taxForm);
    } catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
