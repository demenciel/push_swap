# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 11:25:27 by acouture          #+#    #+#              #
#    Updated: 2023/06/24 13:12:34 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:= -g -Wextra -Wall -Werror

SRC_PATH = src/
OBJ_PATH = obj/

HEADERS	:= -I ./include
SRC		:= main.c \
			parsing/parsing_utils.c \
			parsing/parsing.c \
			sorting/sorting_big.c \
			sorting/sorting_medium.c \
			sorting/sorting_small.c \
			sorting/sorting_utils.c \
			sorting/sorting_utils_2.c \
			lst_utils.c \
			commands/commands1.c \
			commands/commands2.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
LIBFT_A = 	libft.a
LIBF_DIR = 	inc/libft/
LIBFT  = 	$(addprefix $(LIBF_DIR), $(LIBFT_A))

VISUALIZER_DIR := push_swap_visualizer/

GREEN = \033[0;92m
RED = \033[0;91m
RESET = \033[0m

all: makelibft makevisualizer $(NAME)
	@exec 2>/dev/null

makelibft:
	@$(MAKE) -C $(LIBF_DIR)

makevisualizer:
	cd $(VISUALIZER_DIR) && mkdir -p build && cd build && cmake .. && make


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)push_swap compiling: done$(RESET)\n"

debug: $(NAME)
	@$(CC) -g $(OBJS) $(HEADERS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBF_DIR)
	@rm -rf $(OBJ_PATH)
	@printf "$(RED)Push_swap clean: done$(RESET)\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBF_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
