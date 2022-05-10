/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_and_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:24:43 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 19:02:43 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

void	ft_put_image(t_data *va, void *img, void *mlx_ptr, void *win_ptr)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, va->x, va->y);
	va->x = va->x + SIZEPIC;
	va->j++;
}

void	ft_display_images(t_vars *vars)
{
	t_data	va;

	ft_zero_init(&va);
	while (vars->map[va.i])
	{
		while (vars->map[va.i][va.j])
		{
			if (vars->map[va.i][va.j] == '1')
				ft_put_image(&va, vars->img.mur, vars->mlx, vars->win);
			else if (vars->map[va.i][va.j] == '0')
				ft_put_image(&va, vars->img.sol, vars->mlx, vars->win);
			else if (vars->map[va.i][va.j] == 'P')
				ft_put_image(&va, vars->img.perso, vars->mlx, vars->win);
			else if (vars->map[va.i][va.j] == 'C')
				ft_put_image(&va, vars->img.collect, vars->mlx, vars->win);
			else if (vars->map[va.i][va.j] == 'E')
				ft_put_image(&va, vars->img.escape, vars->mlx, vars->win);
		}
		va.i++;
		va.j = 0;
		va.x = 0;
		va.y = va.y + SIZEPIC;
	}
}

void	ft_mlx_win_init(t_vars *vars)
{
	int		win_height;
	int		win_wide;

	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_destroy_map(vars->map);
		ft_print_error_exit("Error\nMlx pointer == NULL");
	}
	ft_img_init(vars);
	win_height = SIZEPIC * ft_map_height(vars->map);
	win_wide = SIZEPIC * ft_map_wide(vars->map);
	vars->win = mlx_new_window(vars->mlx, win_wide, win_height,
			"a FISH");
	if (!vars->win)
		ft_destroy_all_message(vars->map, vars->mlx, &vars->img,
			"Error\nWin pointer == NULL\n");
	ft_display_images(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = (t_vars){0};
	if (argc != 2)
		return (0);
	if (ft_check_ber(argv[1]) == ERROR)
		return (0);
	vars.map = create_map_tab(argv[1]);
	if (!vars.map)
		return (0);
	ft_mlx_win_init(&vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, ft_key_hook, &vars);
	mlx_hook(vars.win, ClientMessage, LeaveWindowMask, ft_mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
