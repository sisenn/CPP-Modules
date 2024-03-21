#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) {
    std::cout << "A new Shrubbery Creation Form has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :AForm("Shrubbery Creation Form", 145, 137), _target(target) {
    std::cout << "A new Shrubbery Creation Form has been created for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) {
    std::cout << "A Shrubbery Creation Form has been copied." << std::endl;
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &otherShrubberyCreationForm) {
    std::cout << "Shrubbery Creation Form has been assigned." << std::endl;
    if (this != &otherShrubberyCreationForm)
        this->_target = otherShrubberyCreationForm.getTarget();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm object is being destroyed." << std::endl;
}

void	ShrubberyCreationForm::action() const {
	std::ofstream file;
	file.open(this->_target + "_shrubbery");
    if (file.is_open() == false)
    {
        std::cout << "Error: file \"" << (this->_target + "_shrubbery") << "\" can not be opened. " << std::endl;
        return ;
    }
	file << 
        "       &&& &&  & &&\n"
    "      && &\\/&\\|& ()|/ @, &&\n"
    "      &\\/(/&/&||/& /_/)_&/_&\n"
    "   &() &\\/&|()|/&\\/ '%\" & ()\n"
    "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
    "&&   && & &| &| /& & % ()& /&&\n"
    " ()&_---()&\\&\\|&&-&&--%---()~\n"
    "     &&     \\|||\n"
    "             |||\n"
    "             |||\n"
    "             |||\n"
    "       , -=-~  .-^- _\n";
    file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	else
		this->action();
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}
