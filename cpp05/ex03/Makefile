NAME = ./a.out
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

OBJ_DIR = obj
SRC = main.cpp Bureaucrat.cpp AForm.cpp  PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
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

.PHONY:  clean re flcean all