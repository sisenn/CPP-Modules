NAME		=	main

SRC			=	main.cpp

OBJS		=	$(SRC:.cpp=.o)

COMPILE		=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILE) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.cpp.o:
	@${COMPILE} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY:	all clean fclean re
