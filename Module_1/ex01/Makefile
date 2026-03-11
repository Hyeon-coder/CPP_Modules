# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 15:35:12 by JuHyeon           #+#    #+#              #
#    Updated: 2025/12/21 19:55:28 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincludes
RM		= rm -rf

SRC_DIR	= src
OBJ_DIR	= obj

SRC = $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/zombieHorde.cpp \
		$(SRC_DIR)/Zombie.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Cleaned up all object files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaned up $(NAME)"

re: fclean all

.PHONY: all clean fclean re