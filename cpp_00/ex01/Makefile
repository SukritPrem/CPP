NAME = Phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp main.cpp Phonebook.cpp

OBJ = (%)
all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all