#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &otherShrubberyCreationForm);
    virtual ~ShrubberyCreationForm();

    void		action() const;
	void		execute(Bureaucrat const & executor) const;
	std::string	getTarget() const;
};

#endif
