NAME		= 	BraiiiiiiinnnzzzZ
HDRS		=	Zombie.hpp
SRCS 		= 	Zombie.cpp \
				randomChump.cpp \
				newZombie.cpp \
				main.cpp
OBJS		=	$(SRCS:.cpp=.o)

CC			= 	c++
FLAGS		= 	-Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) 	: 	$(OBJS) $(HDRS)
				$(CC) $(FLAGS) $(OBJS) -o $@

%.o 		: 	%.cpp $(HDRS)
				$(CC) $(FLAGS) -c $< -o $@

clean 		:
				@rm -f $(OBJS)

fclean 		: 	clean
				@rm -f $(NAME)

re 			: 	fclean all

.PHONY 		: 	all clean fclean re
