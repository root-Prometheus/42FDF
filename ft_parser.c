/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunday <egunday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:34 by                   #+#    #+#             */
/*   Updated: 2023/01/07 18:11:46 by egunday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_valid_file(char *file_path)
{
	char	*line;
	int		fd;

	line = 0;
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		free(line);
	close(fd);
	if (line)
		free(line);
	else
		return (0);
	return (1);
}

int	ft_get_width(char *file_path)
{
	int		counter;
	int		fd;
	char	*line;

	line = 0;
	fd = open(file_path, O_RDONLY);
	get_next_line(fd, &line);
	counter = ft_wdcounter(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	if (line)
		free(line);
	close(fd);
	return (counter);
}

int	ft_get_height(char *file_path)
{
	int		counter;
	char	*line;
	int		fd;

	counter = 0;
	line = 0;
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		counter++;
		free(line);
	}
	free(line);
	close(fd);
	return (counter);
}

void	ft_line_to_numbers(int *array, char *line)
{
	char	**str;
	int		i;

	str = ft_split(line, ' ');
	i = 0;
	while (str[i])
	{
		array[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_parser(char *file_path, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	if (!ft_valid_file(file_path))
		return (0);
	data->height = ft_get_height(file_path);
	data->width = ft_get_width(file_path);
	data->map = ft_calloc_2d(data->height, data->width);
	if (!data->map)
		return (0);
	i = 0;
	line = 0;
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_line_to_numbers(data->map[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (1);
}
