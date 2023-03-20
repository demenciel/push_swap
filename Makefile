# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 11:25:27 by acouture          #+#    #+#              #
#    Updated: 2023/03/20 07:50:43 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:= -g -Wextra -Wall -Werror

HEADERS	:= -I ./include
SRCS	:= ./src/main.c \
			./src/parsing/parsing_utils.c \
			./src/parsing/parsing.c \
			./src/sorting/sorting_small.c \
			./src/sorting/sorting_utils.c \
			./src/lst_utils.c \
			./src/commands/commands1.c \
			./src/commands/commands2.c \
			./utils.c
			
OBJS	:= ${SRCS:.c=.o}
LIBFT_A = 	libft.a
LIBF_DIR = 	inc/libft/
LIBFT  = 	$(addprefix $(LIBF_DIR), $(LIBFT_A))

GREEN = \033[0;92m
RED = \033[0;91m
RESET = \033[0m

all: makelibft $(NAME)
	@exec 2>/dev/null

# run: all
# 	@./$(NAME) 

makelibft:
	@$(MAKE) -C $(LIBF_DIR)
	
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)push_swap compiling: done$(RESET)\n"

debug: $(NAME)
	@$(CC) -g $(OBJS) $(HEADERS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBF_DIR)
	@rm -f $(OBJS)
	@printf "$(RED)Clean: done$(RESET)\n"

	
fclean: clean
	@$(MAKE) fclean -C $(LIBF_DIR)
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx