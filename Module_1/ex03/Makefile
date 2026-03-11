# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 14:10:33 by juhyeonl          #+#    #+#              #
#    Updated: 2025/10/09 14:51:31 by juhyeonl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC_DIR	= ./src
OBJ_DIR	= ./obj

SRCS = $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Weapon.cpp \
		$(SRC_DIR)/HumanA.cpp \
		$(SRC_DIR)/HumanB.cpp
		
OBJ = $(SRCS:$(SRC_DIR)%=$(OBJ_DIR)/%)
OBJ := $(OBJ:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned up all object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up $(NAME)"

re: fclean all
	@echo "Remade everything"

.PHONY: all clean fclean re