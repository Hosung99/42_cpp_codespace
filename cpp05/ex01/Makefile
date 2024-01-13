CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./ex01
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) Bureaucrat.hpp Form.hpp
	$(CPP) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
