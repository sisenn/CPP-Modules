#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form(void);
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(Form const &copy);
	Form &operator=(Form const &otherForm);
    ~Form();

    const std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class AlreadySignedException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif
