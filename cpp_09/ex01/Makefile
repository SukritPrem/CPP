NAME = RPN

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp RPN.cpp

HEADERS = RPN.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
	./RPN "8 9 9 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "7 7 * 7 -"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	./RPN "(1 + 1)"
	# ./RPN "+ 1 + 1"
	# ./RPN "1 + ++-- 1"
	# ./RPN "8 9 ** 9 - 9 - 9 - 4 - 1 +"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJS): %.o: %.cpp $(HEADERS) Makefile
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

.PHONY: all m clean fclean