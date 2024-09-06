NAME	=	ex01

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp Span.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o		:	%.cpp
			@$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean	:
			rm -f $(OBJ)

fclean	:
			rm -f $(OBJ) $(NAME)

re		:	fclean all

.phony	:	all clean fclean re