/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:44 by                   #+#    #+#             */
/*   Updated: 2023/01/07 23:51:43 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_get_line_color(t_point *p1, t_point *p2, t_fdf *data)
{
	int	z1;
	int	z2;

	z1 = data->map[p1->y][p1->x];
	z2 = data->map[p2->y][p2->x];
	if (z1 > z2)
		return (0xff0000);
	if (z1 < z2)
		return (0x0000ff);
	if (z1 > 0)
		return (0x6f00ff);
	if (z1 < 0)
		return (0x00e5ff);
	return (0xffffff);
}

int	**ft_calloc_2d(int n_rows, int n_cols)
{
	int	**p;
	int	i;

	i = 0;
	p = ft_calloc(n_rows, sizeof(int *));
	if (!p)
		return (0);
	while (i < n_rows)
	{
		p[i] = ft_calloc(n_cols, sizeof(int));
		if (!p[i])
		{
			return (0);
		}
		i++;
	}
	return (p);
}

void	ft_clear_map(int **map, t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_exit(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img_ptr);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_clear_map(data->map, data);
	free(data);
	exit(0);
}

int	ft_init_fdf(t_fdf *da)
{
	da->proj = 1;
	if (da->width > 9)
		da->scale = (int) rintf(55 / rintf((float) da->width / 10));
	else
		da->scale = 150;
	da->angle = M_PI / 3;
	da->shift_x = WIN_HEIGHT / 3;
	da->shift_y = WIN_WIDTH / 3;
	da->shift_z = 1;
	da->mlx = mlx_init();
	if (!da->mlx)
		return (0);
	da->mlx_win = mlx_new_window(da->mlx, WIN_HEIGHT, WIN_WIDTH, ".Prmtheus");
	if (!da->mlx_win)
		return (0);
	da->bpp = 32;
	da->size_line = WIN_HEIGHT * 4;
	da->endian = 1;
	da->img_ptr = mlx_new_image(da->mlx, WIN_HEIGHT, WIN_WIDTH);
	da->img_data = mlx_get_data_addr(da->img_ptr, &da->bpp,
			&da->size_line, &da->endian);
	return (1);
}
