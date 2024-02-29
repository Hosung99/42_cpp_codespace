CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./PmergeMe
SRCS = main.cpp PmergeMe.cpp
HEADS = PmergeMe.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADS)
	$(CPP) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
