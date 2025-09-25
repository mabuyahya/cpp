NAME = ./convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Base.cpp main_helper.cpp
OBJ = $(SRC:.cpp=.o)
OBJDIR = obj
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
clean:
	rm -rf $(OBJDIR)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re