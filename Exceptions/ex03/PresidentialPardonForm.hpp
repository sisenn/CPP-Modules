#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &otherPresidentialPardonForm);
    ~PresidentialPardonForm();

    void		action() const;
	void		execute(Bureaucrat const & executor) const;
	std::string	getTarget() const;
};

#endif
