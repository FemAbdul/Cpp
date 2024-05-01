NAME	= zombie

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

all		: $(NAME)

$(NAME)	: $(SRCS)
			@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean	:
			@rm -f $(NAME)

fclean	:
			@rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re