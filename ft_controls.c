/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:12:29 by                   #+#    #+#             */
/*   Updated: 2023/01/07 05:30:13 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_controls_system(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_EXIT && ++finded)
		ft_exit(data);
	return (finded);
}

int	ft_controls_transforms(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_SCALE_PLUS && ++finded)
		data->scale++;
	if (keycode == KEY_SCALE_MINUS && ++finded)
		data->scale--;
	if (keycode == KEY_ROTATE_LEFT && ++finded)
		data->angle += M_PI / 16;
	if (keycode == KEY_ROTATE_RIGHT && ++finded)
		data->angle -= M_PI / 16;
	if (keycode == KEY_HEIGHT_PLUS && ++finded)
		data->shift_z++;
	if (keycode == KEY_HEIGHT_MINUS && ++finded)
		data->shift_z--;
	return (finded);
}

int	ft_controls_move(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_UP && ++finded)
		data->shift_y -= 50;
	if (keycode == KEY_DOWN && ++finded)
		data->shift_y += 50;
	if (keycode == KEY_RIGHT && ++finded)
		data->shift_x += 50;
	if (keycode == KEY_LEFT && ++finded)
		data->shift_x -= 50;
	return (finded);
}

int	ft_controls_proj(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_PROJ_DEF && ++finded)
		data->proj = 0;
	if (keycode == KEY_PROJ_ISO && ++finded)
		data->proj = 1;
	return (finded);
}

int	ft_controls(int keycode, t_fdf *data)
{
	int	key_exists;

	key_exists = 0;
	key_exists |= ft_controls_system(keycode, data);
	key_exists |= ft_controls_transforms(keycode, data);
	key_exists |= ft_controls_move(keycode, data);
	key_exists |= ft_controls_proj(keycode, data);
	return (key_exists);
}
