# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/09 00:00:00 by juhyeonl          #+#    #+#              #
#    Updated: 2026/03/09 00:00:00 by juhyeonl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude
RM		= rm -rf

SRC_DIR	= ./src
OBJ_DIR	= ./obj

SRC = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Base.cpp

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
