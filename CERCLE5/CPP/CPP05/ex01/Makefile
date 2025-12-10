NAME        = Form_up_maggots

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

SRC_FILES   = main.cpp Bureaucrat.cpp Form.cpp
SRC         = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ         = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
