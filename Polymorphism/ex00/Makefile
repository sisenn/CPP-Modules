NAME = fixed

CFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = main.cpp Fixed.cpp

HEADER = Fixed.hpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re