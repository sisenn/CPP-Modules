#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {
	std::cout << "A new Presidential Pardon Form has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) {
	std::cout << "Presidential Pardon has been copied." << std::endl;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &otherPresidentialPardonForm) {
    std::cout << "Presidential Pardon has been assigned." << std::endl;
    if (this != &otherPresidentialPardonForm)
        AForm::operator=(otherPresidentialPardonForm); 
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential Pardon has been destroyed." << std::endl;
}

void	PresidentialPardonForm::action() const {
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	else
		this->action();
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}
