/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:11:03 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 19:08:36 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "gnl/get_next_line.h"

/*	Setting up accessible cases	*/

# define ACCESSIBLE_CASE "0CRLBd"

/*	Setting up keybinds	*/

# define R_KEY 114
# define W_KEY 119
# define A_KEY 97
# define Z_KEY 122
# define P_KEY 112
# define Q_KEY 113
# define S_KEY 115
# define D_KEY 100
# define ESCAPE_KEY 65307
# define UP_KEY 65362
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define DOWN_KEY 65364

/*	Configuration	*/

# define FPS 5
# define WLENGTH 1600
# define WHEIGHT 900
# define TILE_SIZE 100

enum {up, right, down, left};

/* Structures */
/*	Contains minimum and maximum indexes to print on window	*/
typedef struct s_coordmax
{
	int	imin;
	int	imax;
	int	jmin;
	int	jmax;
}	t_coordmax;

/*	Contains current map informations	*/

typedef struct s_map
{
	int		fd;
	int		height;
	int		length;
	int		nb_exit;
	int		nb_player;
	int		nb_collec;
	char	*path;
	char	**map;
}	t_map;

/*	Contains mlx values and many informations	*/

typedef struct s_vars
{
	int		x;
	int		y;
	int		dir;
	int		frames;
	int		offset_x;
	int		offset_y;
	int		life;
	int		level;
	int		killed;
	int		to_kill;
	int		collected;
	int		nb_moves;
	int		pause;
	int		img_width;
	int		img_height;
	char	*objectif;
	char	*settings;
	char	*mobs_to_kill;
	char	**av;
	void	*mlx;
	void	*win;
	void	**images;
	clock_t	begin;
	t_map	map;
	int		koko;
}	t_vars;

/*	Hooks functions	*/

int		exit_hook(t_vars *vars);
int		handle_no_event(t_vars *vars);
int		manage_keycode(t_vars *vars, int keycode, int x, int y);
int		key_hook(int keycode, t_vars *vars);
void	ft_setup_hooks(t_vars *vars);
void	handle_cheatcode(t_vars *vars, int keycode);
void	handle_next(t_vars *vars, int keycode);

/*	Closing functions	*/

void	ft_mlx_close_croix_rouge_de_ses_morts(t_vars *vars);
void	ft_mlx_close(t_vars *vars);
void	ft_mlx_close_game(t_vars *vars);

/*	Multi-level handling	*/

void	ft_mlx_restart(t_vars *vars);
void	ft_next_level(t_vars *vars);
void	ft_begin_level(t_vars *vars);

/*	Move functions	*/

int		ft_move(t_vars *vars, int keycode);
int		is_accessible(t_vars vars, int x, int y, int dir);

int		is_accessible_up(t_vars vars, int x, int y);
int		ft_check_up(t_vars *vars, int x, int y);
void	ft_move_up(t_vars *vars, int x, int y);
int		is_accessible_down(t_vars vars, int x, int y);
int		ft_check_down(t_vars *vars, int x, int y);
void	ft_move_down(t_vars *vars, int x, int y);
int		is_accessible_right(t_vars vars, int x, int y);
int		ft_check_right(t_vars *vars, int x, int y);
void	ft_move_right(t_vars *vars, int x, int y);
int		is_accessible_left(t_vars vars, int x, int y);
int		ft_check_left(t_vars *vars, int x, int y);
void	ft_move_left(t_vars *vars, int x, int y);

/*	Ennemy handling	*/

int		ft_pat_patrouille(t_vars *vars);
int		ft_pat_right(t_vars *vars, int i, int *j);
int		ft_pat_left(t_vars *vars, int i, int j);

/*	Launching game	*/

int		ft_init_map(t_map *map);
int		ft_play(t_vars *vars);
int		ft_read_map(t_map *map);
void	ft_begin_game(t_vars *vars);
void	ft_init_file(t_vars *vars);
void	ft_init_vars(t_vars *vars);
void	**ft_init_images(t_vars *vars);
void	ft_init_images_p2(void **images, t_vars *vars);
void	*read_image(t_vars *vars, char *path);

/*	Map checking functions	*/

int		ft_check_line(t_map *map, int i);
int		ft_check_first_line(char *str);
int		ft_count_lines(t_map map);
int		is_name_valid(char *av);

/*	Utilitaries fonctions	*/

int		ft_atoi(char *s);
int		ft_strlen(const char *str);
int		min(int a, int b);
int		max(int a, int b);
void	ft_cswitch(char *a, char *b);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *s);
char	*ft_so_long_strndup(char *s, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2, int a, int b);
char	*ft_itoa(int n);
void	get_coords(t_vars *vars, int *x, int *y);

/*	Display functions	*/

void	ft_fondu(t_vars *vars);
void	ft_mega_fondu(t_vars *vars);
void	ft_put_pixel_horizontal(t_vars *vars, int i);
void	ft_put_pixel_vertical(t_vars *vars, int i);
void	ft_fill_coraux_bizarres(t_vars *vars);
void	ft_animate_map(t_vars *vars);
void	ft_update_map(t_vars *vars);
void	ft_update_full_map(t_vars *vars);
void	ft_put_img(t_vars *vars, int index, int i, int j);
void	ft_put_img_classic(t_vars *vars, int index, int i, int j);
void	ft_display_map(t_vars *vars);
int		is_adjacent(t_vars *vars, int y, int x);

/*	Display informations	*/

void	ft_print_data(t_vars *vars);
void	ft_print_data_ennemy(t_vars *vars);
void	ft_print_case(t_vars *vars, char c, int i, int j);
void	ft_print_life(t_vars *vars);
void	ft_print_info(t_vars *vars);

/*	Calcul for scrolling	*/

void	ft_calcul_offset_i(t_vars *vars, t_coordmax *cmax);
void	ft_calcul_offset_j(t_vars *vars, t_coordmax *cmax);
void	ft_calcul_decalage(t_vars *vars, int *offset_x, int *offset_y);

/*	Ending program	*/

void	ft_delete_vars(t_vars *vars);

/*	Doors handling	*/

void	check_doors(t_vars *vars);
void	open_doors(t_vars *vars);
void	close_doors(t_vars *vars);

#endif
