NAME    = forms

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Iinclude

SRCS_DIR= src
SRCS    = $(SRCS_DIR)/main.cpp \
          $(SRCS_DIR)/Bureaucrat.cpp \
          $(SRCS_DIR)/AForm.cpp \
          $(SRCS_DIR)/ShrubberyCreationForm.cpp \
          $(SRCS_DIR)/RobotomyRequestForm.cpp \
          $(SRCS_DIR)/PresidentialPardonForm.cpp \
          $(SRCS_DIR)/Intern.cpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
