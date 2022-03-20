NAME = megaphone
FLAGS = -std=c++98 -Wall -Werror -Wextra -o $(NAME)
CC = c++
SRCS = megaphone.cpp

$(NAME):
	$(CC) $(FLAGS) $(SRCS)
all: $(NAME)
fclean:
	rm -f $(NAME)
re:	fclean all

.PHONY: all fclean re
