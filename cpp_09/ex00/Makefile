NAME = btc

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp BitcoinExchange.cpp

HEADERS =  BitcoinExchange.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
	./btc ./data1.csv

$(OBJS): $(HEADERS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	cmake -S . -B build
	cmake --build build
	cd build && ctest


.PHONY: all clean fclean re test
