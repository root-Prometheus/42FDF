/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:07 by egunday           #+#    #+#             */
/*   Updated: 2023/01/07 07:12:08 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_set_pixel(t_point point, int color, t_fdf *data)
{
	int	pxel;

	if (point.y < WIN_WIDTH && point.x < WIN_HEIGHT)
	{
		pxel = (point.y * WIN_HEIGHT * 4) + (point.x * 4);
		color = mlx_get_color_value(data->mlx, color);
		if (point.x > 0 && pxel > 0
			&& pxel < WIN_WIDTH * WIN_HEIGHT * (data->bpp / 8))
		{
			data->img_data[pxel + 0] = (char)((color) & 0xFF);
			data->img_data[pxel + 1] = (char)((color >> 8) & 0xFF);
			data->img_data[pxel + 2] = (char)((color >> 16) & 0xFF);
			data->img_data[pxel + 3] = (char)((color >> 24));
		}
	}
	if (!data->mlx)
		ft_exit(data);
}

t_point	ft_set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	ft_bresenham(t_point p1, t_point p2, t_fdf *data)
{
	int	deltax;
	int	deltay;
	int	error;
	int	error_check;

	ft_transforms(&p1, &p2, data);
	deltax = ft_abs(p2.x - p1.x);
	deltay = ft_abs(p2.y - p1.y);
	error = deltax - deltay;
	ft_set_pixel(p1, data->color, data);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		ft_set_pixel(p1, data->color, data);
		error_check = error * 2;
		if (error_check > -deltay)
		{
			error -= deltay;
			p1.x += ft_nbrcmp(p2.x, p1.x);
		}
		if (error_check < deltax)
		{
			error += deltax;
			p1.y += ft_nbrcmp(p2.y, p1.y);
		}
	}
}

void	ft_draw(t_fdf *data, int clear)
{
	int		x;
	int		y;

	if (clear)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_bzero(data->img_data, WIN_WIDTH * WIN_HEIGHT * (data->bpp / 8));
	}
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham(ft_set_point(x, y), ft_set_point(x + 1, y), data);
			if (y < data->height - 1)
				ft_bresenham(ft_set_point(x, y), ft_set_point(x, y + 1), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_ptr, 0, 0);
	ft_render_text(data);
}
