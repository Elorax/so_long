SRCS		=	so_long.c						\
				gnl/get_next_line.c				\
				gnl/get_next_line_utils.c		\
				srcs/hooks.c					\
				srcs/utils.c					\
				srcs/adj_accessible.c			\
				srcs/close_functions.c			\
				srcs/check_map.c				\
				srcs/ft_init_vars.c				\
				srcs/ft_delete_vars.c			\
				srcs/ft_update_map.c			\
				srcs/ft_begin_game.c			\
				srcs/ft_move.c					\
				srcs/manage_keycode.c

SRCS_BONUS	=	so_long_bonus.c					\
				gnl/get_next_line.c				\
				gnl/get_next_line_utils.c		\
				srcs_bonus/hooks.c				\
				srcs_bonus/utils.c				\
				srcs_bonus/utils2.c				\
				srcs_bonus/bonus_hooks.c 		\
				srcs_bonus/bonus_animation.c 	\
				srcs_bonus/adj_coords.c			\
				srcs_bonus/accessible.c 		\
				srcs_bonus/close_functions.c	\
				srcs_bonus/check_map.c			\
				srcs_bonus/ft_init_vars.c		\
				srcs_bonus/ft_delete_vars.c		\
				srcs_bonus/ft_update_map.c		\
				srcs_bonus/ft_begin_game.c		\
				srcs_bonus/ft_move.c			\
				srcs_bonus/manage_keycode.c		\
				srcs_bonus/ft_pat_patrouille.c	\
				srcs_bonus/check_doors.c		\
				srcs_bonus/ft_move_left.c		\
				srcs_bonus/ft_move_right.c		\
				srcs_bonus/ft_move_up.c			\
				srcs_bonus/ft_move_down.c		\
				srcs_bonus/images.c				\
				srcs_bonus/ft_calcul_offset.c	\
				srcs_bonus/fill.c				\
				srcs_bonus/fondu.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC		= clang
RM		= rm -rf

CFLAGS = -Wall -Wextra -Werror -g3

NAME=	so_long

NAME_BONUS=	so_long_bonus

PATH_MLX		=./minilibx


%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

LINUX		= -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

$(NAME): $(OBJS)
		make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS) minilibx/libmlx_Linux.a $(LINUX) -o $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)

fclean:		clean
		make -C $(PATH_MLX) clean
		rm -rf $(NAME)

re:		fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
		make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS_BONUS) minilibx/libmlx_Linux.a $(LINUX) -o $(NAME_BONUS)

.PHONY:		all clean fclean re bonus
