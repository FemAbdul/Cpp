NAME	= megaphone

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= megaphone.cpp

all	: $(NAME)

$(NAME) :	$(SRC)
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean	:	
			@rm -f $(NAME)

fclean	:
			@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re	

