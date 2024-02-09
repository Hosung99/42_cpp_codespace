CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./btc
SRCS = main.cpp BitcoinExchange.cpp
HEADS = BitcoinExchange.hpp
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
