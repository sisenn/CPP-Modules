#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include <fstream>
# include <sstream>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm(void);
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &copy);
	AForm &operator=(AForm const &otherAForm);
    virtual ~AForm();

    const std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat& bureaucrat);
    virtual void	action() const = 0;
	virtual void 	execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

    class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
