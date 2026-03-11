# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 16:47:57 by JuHyeon           #+#    #+#              #
#    Updated: 2026/01/06 07:13:45 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude
RM		= rm -rf

SRC_DIR	= ./src
OBJ_DIR	= ./obj

SRC = $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Animal.cpp \
		$(SRC_DIR)/Dog.cpp \
		$(SRC_DIR)/Cat.cpp \
		$(SRC_DIR)/WrongCat.cpp \
		$(SRC_DIR)/WrongAnimal.cpp \
		$(SRC_DIR)/Brain.cpp

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

.PHONY: all clean fclean re% 