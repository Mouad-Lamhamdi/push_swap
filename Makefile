# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molamham <molamham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 21:01:39 by molamham          #+#    #+#              #
#    Updated: 2025/02/18 14:32:29 by molamham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @cc

NAME = push_swap

ARCHIVE = push_swap.a

FLAGS = -Wall -Wextra -Werror -g

SRC = errors.c ft_atoi.c ft_split.c init_nodes_a.c init_nodes_b.c linked_list.c push_swap.c \
		quick_sort.c sort_stack.c stack_init.c stack_utils.c operations/push.c \
		operations/rev_rotate.c operations/rotate.c operations/swap.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)

$(ARCHIVE) : $(OBJ)
	@echo "push_swap compiled"

%.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@
	@ar rcs $(ARCHIVE) $@

bonus : all
	@cd Checker && make

clean :
	@rm -rf $(OBJ)
	@cd Checker && make clean
	@echo "Clean"

fclean : clean
	@rm -rf $(NAME) $(ARCHIVE)
	@rm -rf checker
	@cd Checker && rm -rf checker

re : fclean all

.PHONY : all clean
