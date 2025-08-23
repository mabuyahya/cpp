CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
OBJ_DIR = obj
OBJ := $(addprefix $(OBJ_DIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: re all fclean clean