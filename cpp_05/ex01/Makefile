NAME = a.out

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp Bureaucrat.cpp Form.cpp 

HEADERS =  Bureaucrat.hpp Form.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(OBJS): $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re