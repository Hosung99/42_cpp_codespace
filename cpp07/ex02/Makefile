CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./ex02
SRCS = main.cpp
HEADS = Array.hpp Array.tpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(HEADS)
	$(CPP) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
