/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:50:22 by                   #+#    #+#             */
/*   Updated: 2023/01/07 19:23:19 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "./minilibx_macos/mlx.h"
# define WIN_HEIGHT 1920
# define WIN_WIDTH 1080
# define T_OFFSET 50
# define T_HEIGHT 17
# define T_COLOR 0xfa
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_EXIT 53
# define KEY_ROTATE_LEFT 12
# define KEY_ROTATE_RIGHT 14
# define KEY_SCALE_PLUS 6
# define KEY_SCALE_MINUS 7
# define KEY_HEIGHT_PLUS 3
# define KEY_HEIGHT_MINUS 5
# define KEY_PROJ_DEF 34
# define KEY_PROJ_ISO 35

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**map;
	int		color;
	int		scale;
	float	angle;
	int		proj;
	int		shift_x;
	int		shift_y;
	int		shift_z;
	void	*mlx;
	void	*mlx_win;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img_ptr;
	char	*img_data;
	int		ch;
}			t_fdf;

void	menuselection(void);
void	data(char **argv);
int		keyhandler(int keygen, t_fdf *datar);
int		ft_parser(char *file_path, t_fdf *data);
void	ft_draw(t_fdf *data, int init);
int		ft_controls(int keycode, t_fdf *data);
void	ft_transforms(t_point *p1, t_point *p2, t_fdf *data);
void	ft_render_text(t_fdf *data);
int		ft_init_fdf(t_fdf *data);
int		**ft_calloc_2d(int n_rows, int n_cols);
int		ft_get_line_color(t_point *p1, t_point *p2, t_fdf *data);
void	ft_exit(t_fdf *data);
void	ft_clear_map(int **map, t_fdf *data);

#endif
