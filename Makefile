CC = @cc

NAME = push_swap

BNAME = checker

FLAGS = -Wall -Wextra -Werror 

SRC = errors.c ft_atoi.c ft_split.c init_nodes_a.c init_nodes_b.c linked_list.c push_swap.c \
		quick_sort.c sort_stack.c stack_init.c stack_utils.c operations/push.c \
		operations/rev_rotate.c operations/rotate.c operations/swap.c

BSRC = Checker/checker.c Checker/checker_utils.c Checker/get_next_line.c Checker/get_next_line_utils.c \
		errors.c ft_atoi.c ft_split.c init_nodes_a.c init_nodes_b.c linked_list.c \
		quick_sort.c sort_stack.c stack_init.c stack_utils.c operations/push.c \
		operations/rev_rotate.c operations/rotate.c operations/swap.c

OBJ = $(SRC:%.c=%.o)

BOBJ = $(BSRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Push_swap compiled !"
bonus : $(BNAME)

$(BNAME) : $(BOBJ)
	$(CC) $(FLAGS) $(BOBJ) -o $(BNAME)
	@echo "Checker compiled !"

%.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@

clean :
	@rm -rf $(OBJ) $(BOBJ)
	@echo "Object files removed !"

fclean : clean
	@rm -rf $(NAME) $(BNAME)
	@echo "Executables removed !"

re : fclean all

.PHONY : all bonus clean
