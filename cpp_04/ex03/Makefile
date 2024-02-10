NAME = a.out

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp  AMateria.cpp  Ice.cpp   MateriaSource.cpp

HEADERS =  AMateria.hpp Ice.hpp  MateriaSource.hpp IMateriaSource.hpp

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