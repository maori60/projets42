# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 21:13:48 by vbui              #+#    #+#              #
#    Updated: 2025/02/04 06:22:55 by vbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
