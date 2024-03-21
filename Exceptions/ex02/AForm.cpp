#include "AForm.hpp"

AForm::AForm(void) : _name("AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "A new form named 'AForm' has been created." << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "A new form has been copied from '" << copy.getName() << "'." << std::endl;
    *this = copy;
}

AForm &AForm::operator=(AForm const &otherAForm) {
	this->_isSigned = otherAForm._isSigned;
    std::cout << "A form has been assigned to '" << this->_name << "'." << std::endl;
	return *this;
}

AForm::~AForm() {
     std::cout << "A form named '" << this->_name << "' has been destroyed." << std::endl;
}

const std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getSign() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if(this->_isSigned)
		throw AlreadySignedException();
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

const char* AForm::AlreadySignedException::what()const throw(){
	return "That FORM has been already SIGNED!\n";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << form.getName() << " form is";
	if (form.getSign())
		os <<  " signed. This form requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	else
		os << " not signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	return os;
}
