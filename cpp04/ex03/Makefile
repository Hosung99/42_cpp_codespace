CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./ex03
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp MateriaBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CPP) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
