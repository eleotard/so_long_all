/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:38:32 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 19:27:13 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx_linux/mlx.h"
# include "get_next_line_bonus.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define ERROR			(-1)
# define BUFFER_SIZE	1
# define COMPTEUR		80000

# define SIZEPIC		60

typedef struct s_gestion
{
	void	*sol;
	void	*mur;
	void	*perso;
	void	*collect;
	void	*escape;
	void	*bg;
	char	*relative_path;
	char	*relative_path2;
	char	*relative_path3;
	char	*relative_path4;
	char	*relative_path5;
	char	*relative_path6;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_data {
	int		i;
	int		j;
	int		x;
	int		y;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_img	img;
}	t_vars;

/*FONCTIONS CLASSIQUES*/
char	*ft_strjoin_s(char *base, char *read);
char	*join(char *base, char *read);
int		ft_strcmp(char *s1, char *s2);

/*FREE ET ERREURS*/
void	ft_destroy_all_message(char **map, void	*mlx, t_img *img,
			char *message);
void	ft_print_error_exit(char *error);
void	ft_destroy_all(char **map, void *mlx, void *win, t_img *img);
void	ft_destroy_map(char **map);

/*CREATION MAP ET CARACTERISTIQUES*/
char	*create_map_str(char *map_name);
char	**create_map_tab(char *map_name);
int		ft_map_height(char **map);
int		ft_map_wide(char **map);

/*VERIF MAP ET SOURCE*/
int		ft_check_ber(char *map_name);
int		ft_check_map_edges(char **map);
int		check_edges_char(char **map, char c);
int		ft_check_rectangular_map(char **map);
int		ft_check_valid_map(char **map);
int		ft_parsing_check(char *map_str);
int		ft_check_occurence(char **map);
void	ft_count_check_occurence(int *count_p, int *count_e,
			int *count_c, char c);

/*INITIALISATION STRUCTURES*/
void	ft_zero_init(t_data *va);
void	ft_img_init(t_vars *vars);
void	ft_set_relative_path(t_vars *vars);
void	ft_check_image(t_vars *vars, void *img);
void	ft_check_edges_init(t_data *co, char **map);

/*EVENT GESTION*/
int		ft_key_hook(int keycode, t_vars *vars);
int		ft_mouse_hook(t_vars *vars);
void	ft_close(t_vars *vars);

/*MOOVES*/
void	ft_move_left(t_vars *vars, int *count);
void	ft_move_right(t_vars *vars, int *count);
void	ft_move_up(t_vars *vars, int *count);
void	ft_move_down(t_vars *vars, int *count);
int		ft_swap_perso(t_vars *vars, char *position, char *swap, int *count);

void	ft_print_moves_and_display(t_vars *vars, int *count);
int		ft_check_collectibles(t_vars *vars);

void	ft_display_images(t_vars *vars);
void	ft_display_txt_background(t_vars *vars);
void	ft_display_str_and_number(char *str, int *count);
void	ft_swap(char *position, char *swap);

#endif
