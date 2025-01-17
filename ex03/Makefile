# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/11/21 16:15:58 by sakitaha          #+#    #+#              #
#    Updated: 2024/11/23 19:43:06 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
NAME	 := ex03
SRCS     := AMateria.cpp \
			Character.cpp \
			Cure.cpp \
			Ice.cpp \
			MateriaSource.cpp \
			main.cpp
OBJS     := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: CXXFLAGS += -DDISPLAY_MSG
test: re
	@echo "== Running Tests  =="
	./$(NAME)
	@echo "== Tests Completed =="

debug: CXXFLAGS += -fsanitize=address -g
debug: $(NAME)
	./$(NAME)

valgrind: all
	valgrind --leak-check=full ./$(NAME)

leaks: all
	leaks -q -atExit -- ./$(NAME)

.PHONY: all clean fclean re test debug leaks valgrind leaks
