#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;
        
        Bureaucrat invalid("Jason", 200);
    } catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
