#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {
    std::cout << "A new Robotomy Request Form has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
    std::cout << "A new Robotomy Request Form has been created for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) {
    std::cout << "A Robotomy Request Form has been copied." << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &otherRobotomyRequestForm) {
    std::cout << "Robotomy Request Form has been assigned." << std::endl;
    this->_target = otherRobotomyRequestForm.getTarget();
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy Request Form destroyed." << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	else
		this->action();
}

void	RobotomyRequestForm::action() const {
	std::cout << "Vınnn... Vıınnn... Drrrr... " << std::endl;
	std::srand(std::time(0));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization has failed." << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}


