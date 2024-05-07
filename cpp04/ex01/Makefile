NAME	= animal

CC  	= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJ		= $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c  $< -o $@

$(NAME)	: $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all		: $(NAME)

clean	:
			@rm -f $(OBJ)

fclean	:
			@rm -f $(NAME) $(OBJ)
			
re		: fclean all

.PHONY	: all clean fclean re