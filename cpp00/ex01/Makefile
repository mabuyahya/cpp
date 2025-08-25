CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
NAME = phonebook
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJ_DIR = obj
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJS))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean

