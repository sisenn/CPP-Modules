#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <sstream>
#include <iostream>

class Brain {

    private:

        std::string Ideas[100];

    public:

        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);

        std::string *getIdeas(void);
		std::string getIdea(int idea) const;
};

#endif
