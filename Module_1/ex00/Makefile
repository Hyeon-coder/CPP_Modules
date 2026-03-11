# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 20:09:43 by JuHyeon           #+#    #+#              #
#    Updated: 2025/12/20 22:04:33 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zombie
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Iincludes
RM          = rm -rf

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= $(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Zombie.cpp \
				$(SRC_DIR)/newZombie.cpp \
				$(SRC_DIR)/randomChump.cpp
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