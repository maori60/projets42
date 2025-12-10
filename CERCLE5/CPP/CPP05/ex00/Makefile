NAME    = bureaucrat

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -I include

SRCS    = src/main.cpp \
          src/Bureaucrat.cpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.cpp include/Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
