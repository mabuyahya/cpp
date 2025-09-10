NAME = ./a.out
CXX = c++
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:%.cpp=%.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:  clean re fclean all