NAME  = ./animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  -MMD -MP

SRC = main.cpp AMateria.cpp Cure.cpp Ice.cpp  Character.cpp  MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)
OBJ_DIR = obj
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
