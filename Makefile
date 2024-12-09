NAME = push_swap
NAME_BONUS = checker
SRC = src/push_swap.c src/split_arg.c src/handl_error.c \
		src/ft_free.c src/creat_stack.c src/lis.c src/push_swap_utils.c src/init_stack.c \
			src/move_stack.c src/short_stack.c \
				moves/push.c moves/rotate.c moves/rrotate.c moves/swap.c
SRC_BONUS = src_bonus/checker.c src_bonus/g_n_l/get_next_line.c src_bonus/g_n_l/get_next_line_utils.c \
				src_bonus/creat_stack_bonus.c src_bonus/ft_free_bonus.c src_bonus/handl_error_bonus.c \
					src_bonus/move_1.c src_bonus/move_2.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
HEADER = push_swap.h checker.h
DIR_OBJ = .object
DIR_OBJ_BONUS = .object_bonus

PATH_LIBFT = ./libft
LIBFT = $(PATH_LIBFT)/libft.a

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@mkdir -p $(DIR_OBJ) && mv $(OBJ) $(DIR_OBJ)
	@echo "TOUT EST MAKE"

bonus : $(OBJ_BONUS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT)
	@mkdir -p $(DIR_OBJ_BONUS) && mv $(OBJ_BONUS) $(DIR_OBJ_BONUS)
	@echo "TOUT BONUS EST MAKE"
	

clean :
	@$(RM) $(OBJ) $(DIR_OBJ)
	@$(RM) $(OBJ_BONUS) $(DIR_OBJ_BONUS)
	@make -C $(PATH_LIBFT) clean

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make -C $(PATH_LIBFT) fclean
	@echo "TOUT EST CEAN"

re : fclean all

.PHONY : clean all