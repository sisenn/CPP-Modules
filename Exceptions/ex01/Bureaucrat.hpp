#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(void);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    Bureaucrat &operator=(Bureaucrat const &otherBureaucrat);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
