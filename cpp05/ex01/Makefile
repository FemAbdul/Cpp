NAME	=	ex01

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp Bureaucrat.cpp Form.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o	: 	%.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

all :	$(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
		@rm -f $(OBJ)

fclean :
		@rm -f $(NAME) $(OBJ)

re		: fclean all

.phony : all clean fclean re