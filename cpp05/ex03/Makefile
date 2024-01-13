CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = ./ex03
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberryCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEADS = Bureaucrat.hpp AForm.hpp ShrubberryCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
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
