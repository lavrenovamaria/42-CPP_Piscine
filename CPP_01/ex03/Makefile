NAME		= 	UnnecessaryViolence
HDRS		=	Weapon.hpp HumanA.hpp HumanB.hpp
SRCS 		= 	HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp \
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
