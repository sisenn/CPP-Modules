NAME = Scavtrap

CFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
