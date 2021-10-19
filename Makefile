NAME = push_swap

SRC = 	push_swap.c		ft_handler.c	ft_swap.c		ft_push.c			ft_rotate.c			ft_rotate_revers.c	\
		ft_check_sort.c	ft_check_dup.c	ft_pos_rec.c	ft_small_sort.c		ft_count_step.c		ft_find_last_elem.c	\
		ft_find_min.c	ft_find_max.c	ft_markup_a.c	ft_check_markup.c	ft_count_step_up.c	ft_scan_min_step.c	\
		error.c			ft_index.c		ft_lst_size.c	ft_middle_sort.c	ft_lst_function.c						\


OBJ = $(patsubst %.c,%.o,$(SRC))

INC = push_swap.h

CFLAGS = -Wall -Wextra -Werror

all : libft $(NAME)

$(NAME) : $(OBJ)
	 gcc -Llibft -lft $(OBJ) -o $@

%.o : %.c $(INC)
	gcc $(CFLAGS) -I./Libft -c $< -o $@

libft :
	make -C Libft/

clean :
	rm -f $(OBJ) $(OBJ_B)
	make clean -C Libft/

fclean : clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re : fclean all

.PHONY : clean fclean libft re all