NAME = TowardsMoreUsefulFixedPointNumberClass

SRCS = main.cpp Fixed.cpp

HEADER = Fixed.hpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -g -std=c++98 -Wall -Wextra -Werror

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS) $(HEADER)
	clang++ $(FLAGS) -o $(NAME) $(OBJS) -I./

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
