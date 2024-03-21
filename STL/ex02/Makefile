NAME = PmergeMe

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp 

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@clang++ $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re