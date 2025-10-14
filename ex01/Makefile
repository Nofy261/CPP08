# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 10:00:48 by nolecler          #+#    #+#              #
#    Updated: 2025/10/14 10:03:55 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CC = c++

CFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98

SRC :=	srcs/Span.cpp \
		srcs/main.cpp

OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re