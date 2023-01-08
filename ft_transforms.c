/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transforms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:38 by                   #+#    #+#             */
/*   Updated: 2023/01/07 23:06:40 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_proj_isometric(t_point *point, float angle, int z)
{
	point->x = (int)round((point->x - point->y) * cos(angle));
	point->y = (int)round((point->x + point->y) * sin(angle) - z);
}

void	ft_proj_def(t_point *point, int z)
{
	if (z != 0)
	{
		point->x = (int)round((point->x) * cos(M_PI / 4));
		point->y = (int)round((point->y) * sin(M_PI / 4));
	}
}

void	ft_scale(t_point *p1, t_point *p2, int value)
{
	p1->x *= value;
	p1->y *= value;
	p2->x *= value;
	p2->y *= value;
}

void	ft_shift(t_point *p1, t_point *p2, int x_val, int y_val)
{
	p1->x += x_val;
	p1->y += y_val;
	p2->x += x_val;
	p2->y += y_val;
}

void	ft_transforms(t_point *p1, t_point *p2, t_fdf *data)
{
	int	z1;
	int	z2;
	int	shift_z;

	data->color = ft_get_line_color(p1, p2, data);
	shift_z = data->shift_z;
	z1 = data->map[p1->y][p1->x] * shift_z;
	z2 = data->map[p2->y][p2->x] * shift_z;
	ft_scale(p1, p2, data->scale);
	if (data->proj == 0)
	{
		ft_proj_def(p1, z1);
		ft_proj_def(p2, z2);
	}
	else
	{
		ft_proj_isometric(p1, data->angle, z1);
		ft_proj_isometric(p2, data->angle, z2);
	}
	ft_shift(p1, p2, data->shift_x, data->shift_y);
}
