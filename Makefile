# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:13:49 by nolecler          #+#    #+#              #
#    Updated: 2025/10/10 09:13:57 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = find

CC = c++

CFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98

SRC :=	srcs/main.cpp

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