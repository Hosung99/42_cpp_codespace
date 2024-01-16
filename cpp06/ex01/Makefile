CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./ex01
SRCS = main.cpp Serialization.cpp
HEADS = Serialization.hpp
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
