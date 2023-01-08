/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfdvm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 05:24:33 by egunday           #+#    #+#             */
/*   Updated: 2023/01/07 06:48:22 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_exit_button(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_clear_map(data->map, data);
	free(data);
	exit(0);
}

int	ft_key_mlx(int keycode, t_fdf *data)
{
	int	key_exists;

	key_exists = ft_controls(keycode, data);
	if (key_exists)
		ft_draw(data, 1);
	return (0);
}

void	data(char **argv)
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	if (!data)
		perror("malloc error");
	if (!ft_parser(argv[0], data) || !ft_init_fdf(data))
	{
		perror("Map not found or has invalid format!");
		free(data);
	}
	ft_draw(data, 0);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_exit_button, data);
	mlx_key_hook(data->mlx_win, ft_key_mlx, data);
	mlx_loop(data->mlx);
}
