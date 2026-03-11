# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 13:27:29 by JuHyeon           #+#    #+#              #
#    Updated: 2025/12/20 09:39:33 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	tests
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -Iincludes
RM		=	rm -rf

SRC_DIR = src
OBJ_DIR = obj

LOG_REF = 19920104_091532.log
LOG_MINE = my_log.txt

SRC		= $(SRC_DIR)/Account.cpp \
			$(SRC_DIR)/tests.cpp

OBJ 	= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

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

check:
	@echo "diff <(cut -d ' ' -f2- 19920104_091532.log) <(cut -d ' ' -f2- my_log.txt)"

.PHONY: all clean fclean re