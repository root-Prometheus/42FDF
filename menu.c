/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 05:30:34 by egunday           #+#    #+#             */
/*   Updated: 2023/01/07 08:06:38 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	keyhandler3(int keygen, char **argv)
{
	if (keygen == 16)
		argv[0] = "./maps/plat.fdf";
	if (keygen == 32)
		argv[0] = "./maps/pnp_flat.fdf";
	if (keygen == 34)
		argv[0] = "./maps/pylone.fdf";
	if (keygen == 31)
		argv[0] = "./maps/pyra.fdf";
	if (keygen == 35)
		argv[0] = "./maps/pyramide.fdf";
	if (keygen == 0)
		argv[0] = "./maps/t1.fdf";
	if (keygen == 1)
		argv[0] = "./maps/t2.fdf";
	data(argv);
	free(argv);
	return (0);
}

int	keyhandler2(int keygen, char **argv)
{
	if (keygen == 28)
		argv[0] = "./maps/elem-col.fdf";
	if (keygen == 25)
		argv[0] = "./maps/elem-fract.fdf";
	if (keygen == 29)
		argv[0] = "./maps/elem.fdf";
	if (keygen == 13)
		argv[0] = "./maps/elem2.fdf";
	if (keygen == 14)
		argv[0] = "./maps/julia.fdf";
	if (keygen == 15)
		argv[0] = "./maps/mars.fdf";
	if (keygen == 17)
		argv[0] = "./maps/pentenegpos.fdf";
	keyhandler3(keygen, argv);
	return (0);
}

int	keyhandler1(int keygen, t_fdf *datar)
{
	char	**argv;

	(void)datar;
	argv = (char **)malloc(1 * sizeof(char **));
	if (keygen == 18)
		argv[0] = "./maps/10-2.fdf";
	if (keygen == 19)
		argv[0] = "./maps/10-70.fdf";
	if (keygen == 20)
		argv[0] = "./maps/20-60.fdf";
	if (keygen == 21)
		argv[0] = "./maps/42.fdf";
	if (keygen == 23)
		argv[0] = "./maps/50-4.fdf";
	if (keygen == 22)
		argv[0] = "./maps/100-6.fdf";
	if (keygen == 26)
		argv[0] = "./maps/basictest.fdf";
	keyhandler2(keygen, argv);
	return (0);
}

void	menudvm(t_fdf *ar)
{
	mlx_string_put (ar->mlx, ar->mlx_win, 600, 900, 0xfa, "I-)pylone.fdf");
	mlx_string_put (ar->mlx, ar->mlx_win, 600, 950, 0xfa, "o-)pyra.fdf");
	mlx_string_put (ar->mlx, ar->mlx_win, 600, 1000, 0xfa, "P-)pyramide.fdf");
	mlx_string_put (ar->mlx, ar->mlx_win, 600, 1010, 0xfa, "A-)t1.fdf");
	mlx_string_put (ar->mlx, ar->mlx_win, 600, 1030, 0xfa, "S-)t2.fdf");
}

void	menuselection(void)
{
	t_fdf	*ro;

	ro = malloc(sizeof(t_fdf));
	ro->mlx = mlx_init();
	ro->mlx_win = mlx_new_window (ro->mlx, 1920, 1080, ".P.rometheus/");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 100, 0xfa, "1-)10-2.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 150, 0xfa, "2-)10-70.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 200, 0xfa, "3-)20-60.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 250, 0xfa, "4-)42.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 300, 0xfa, "5-)50-4.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 350, 0xfa, "5-)50-4.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 400, 0xfa, "7-)basictest.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 450, 0xfa, "8-)elem-col.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 500, 0xfa, "9-)elem-fract.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 550, 0xfa, "0-)elem.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 600, 0xfa, "W-)elem2.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 650, 0xfa, "E-)julia.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 700, 0xfa, "R-)mars.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 750, 0xfa, "T-)pentenegpos.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 800, 0xfa, "Y-)plat.fdf");
	mlx_string_put (ro->mlx, ro->mlx_win, 600, 850, 0xfa, "U-)pnp-flat.fdf");
	menudvm(ro);
	mlx_key_hook(ro->mlx_win, keyhandler1, ro);
	mlx_loop(ro->mlx);
}
