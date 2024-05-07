NAME	= fixed

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRC	= main.cpp Fixed.cpp

OBJ		= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c  $< -o $@

all		: $(NAME)

$(NAME)	: $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean	:
			@rm -f $(OBJ)

fclean	:
			@rm -f $(NAME) $(OBJ)

re		:	fclean all

.PHONY	: all clean fclean re