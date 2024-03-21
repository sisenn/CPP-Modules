#include "Form.hpp"

Form::Form() : _name("Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){
     std::cout << "A new form named 'Form' has been created." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    else
        std::cout << "A new form named '" << name << "' has been created." << std::endl;
}

Form::Form(Form const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "A new form has been copied from '" << copy.getName() << "'." << std::endl;
    *this = copy;
}

Form &Form::operator=(Form const &otherForm) {
	this->_isSigned = otherForm._isSigned;
    std::cout << "A form has been assigned to '" << this->_name << "'." << std::endl;
	return *this;
}

Form::~Form() {
    std::cout << "A form named '" << this->_name << "' has been destroyed." << std::endl;
}

const std::string Form::getName() const {
    return this->_name;
}

bool Form::getSign() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (this->_isSigned)
		throw AlreadySignedException();
    if (bureaucrat.getGrade() <= _gradeToSign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade is too low";
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "That form has been already signed!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << " form is";
	if (form.getSign())
		os << " signed. This form requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	else
		os << " not signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";;
    return os;
}
