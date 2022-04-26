/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:25:06 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/26 20:52:14 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_matrix(t_sl *data)
{
	int	i;
	int	j;

	data->x_nate = -1;
	data->y_nate = -1;
	data->n_collectibles = 0;
	data->e_flag = 0;
	data->m = 0;
	i = 0;
	while (data->matrix[i] != NULL)
	{
		j = 0;
		while (data->matrix[i][j] != '\0')
		{
			check_m(data, i, j);
			if (data->matrix[i][j] == 'P')
				get_nate(data, i, j);
			if (data->matrix[i][j] == 'C')
				data->n_collectibles++;
			if (data->matrix[i][j] == 'E')
				data->e_flag = 1;
			j++;
		}
		i++;
	}
}

int	get_matrix(char *s, t_sl *data)
{
	int		i;
	int		fd;
	char	*line;

	data->matrix = (char **) malloc (sizeof(char *) * (data->height + 1));
	ft_check_malloc(data->matrix);
	data->matrix[data->height] = NULL;
	fd = open(s, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = (char *) malloc (sizeof(char) * (data->len + 1));
		ft_check_malloc(data->matrix[i]);
		line = get_next_line(fd);
		ft_strlcpy (data->matrix[i], line, data->len + 1);
		free(line);
		i++;
	}
	close (fd);
	check_matrix(data);
	if (data->x_nate == -1 || data->n_collectibles <= 0 || data->e_flag == 0)
		return (0);
	return (1);
}

int	check_len(char *s, t_sl *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	data->len = i;
	while (line != NULL)
	{
		data->height++;
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		if (data->len != i)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	if (data->height < 3 || data->len < 3)
		return (0);
	return (1);
}

int	get_map(char *s, t_sl *data)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i < 4 || s[i - 4] != '.' || s[i - 3] != 'b'
		|| s[i - 2] != 'e' || s[i - 1] != 'r')
		return (0);
	data->height = 0;
	if (check_len(s, data) == 0)
		return (0);
	if (get_matrix(s, data) == 0)
		free_and_exit(data, "Map error");
	data->frame = 1;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_sl	data;

	if (argc != 2)
		ft_error("Arg");
	if (get_map(argv[1], &data) == 0)
		ft_error("Map");
	data.mlx = mlx_init();
	convert_images(&data);
	data.window = mlx_new_window
		(data.mlx, (data.len * 64), (data.height * 64), "so_long");
	ft_draw(&data);
	mlx_loop_hook(data.mlx, ft_draw, &data);
	mlx_key_hook(data.window, key_handler, &data);
	mlx_loop(data.mlx);
}
