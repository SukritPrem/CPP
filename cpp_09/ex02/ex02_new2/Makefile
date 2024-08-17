NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp 

HEADERS = PmergeMe.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
	./PmergeMe 1 2 33 44 17 3 4 5 9 8 6 19 11 10

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp $(HEADERS) Makefile
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

.PHONY: all m clean fclean