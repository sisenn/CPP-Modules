#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "A new bureaucrat took office!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
	else
	    this->_grade = grade;
    std::cout << this->_name << " took office!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "A new bureaucrat copied from " << copy.getName() << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &otherBureaucrat) {
	this->_grade = otherBureaucrat._grade;
	std::cout << "Bureaucrat " << otherBureaucrat.getName() << " copied successfully." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat object has been successfully deleted." << std::endl;
}

std::string	Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void	Bureaucrat::incrementGrade() {
	if(this->_grade > 1 && this->_grade <=150){
		this->_grade--;
		std::cout << this->_name << " has been promoted to a higher grade!" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if(this->_grade < 150 && this->_grade >= 1){
		this->_grade++;
		std::cout << "Oops! " << this->_name << " took a step down the bureaucratic ladder." << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void	Bureaucrat::signForm(Form &form) {
	if (form.getSign())
		std::cout << this->_name << " cannot sign " << form.getName() << " because it's already signed." << std::endl;
	else if (this->_grade <= form.getGradeToSign()) {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " because he's grade insufficient." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
