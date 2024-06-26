NAME	=	ex03

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp Intern.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp 

OBJ		=	$(SRC:.cpp=.o)

%.o	: 	%.cpp
		@$(CC) $(CFLAGS) -c $< -o $@



$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
all :	$(NAME)
clean : 
		@rm -f $(OBJ)

fclean :
		@rm -f $(NAME) $(OBJ)

re		: fclean all

.phony : all clean fclean re