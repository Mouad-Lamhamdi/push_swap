CC = cc

NAME = checker

FLAGS = -Wall -Wextra -Werror

SRC = checker.c checker_utils.c get_next_line.c get_next_line_utils.c

PUSH_SWAP_ARCHIVE = ../push_swap.a

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) $(PUSH_SWAP_ARCHIVE)
	$(CC) $^ -o $(NAME)
	cp $(NAME) ../

%.o : %.c
	$(CC) -c $(FLAGS) $< -o $@
	
$(PUSH_SWAP_ARCHIVE) :
	cd ../ && make

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	cd ../ && rm -rf $(NAME)

re : fclean all

.PHONY : all clean