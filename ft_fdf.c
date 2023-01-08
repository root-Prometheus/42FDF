/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:21 by egunday           #+#    #+#             */
/*   Updated: 2023/01/08 00:14:26 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	keyhandler(int keycode, t_fdf *dataf)
{
	char	**temp;

	temp = (char **)malloc(1 * sizeof(char));
	if (keycode == 18)
	{
		free(dataf);
		mlx_destroy_window(dataf->mlx, dataf->mlx_win);
		menuselection();
	}
	if (keycode == 19)
	{
		free(dataf);
		mlx_destroy_window(dataf->mlx, dataf->mlx_win);
		temp[0] = "./maps/test16x16.fdf";
		data(temp);
		free(temp);
	}
	if (keycode == 20)
		exit(1);
	return (0);
}

int	main(void)
{
	t_fdf	*da;

	da = malloc(sizeof(t_fdf));
	da->mlx = mlx_init();
	da->mlx_win = mlx_new_window (da->mlx, 1920, 1080, ".P.rometheus/");
	mlx_string_put (da->mlx, da->mlx_win, 600, 400, 0xfa, "1-)Harita Sec");
	mlx_string_put (da->mlx, da->mlx_win, 600, 500, 0xfa, "2-)bonus");
	mlx_string_put (da->mlx, da->mlx_win, 600, 600, 0xfa, "3-)Cikis Yap");
	mlx_key_hook (da->mlx_win, keyhandler, da);
	mlx_loop(da->mlx);
}
