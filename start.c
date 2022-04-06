/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:25:06 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/06 20:20:28 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_matrix(char *s, t_sl *data)
{
	int		i;
	int		fd;
	char	*line;
	//t_flags	flags;

	data->matrix = (char **) malloc (sizeof(char *) * data->height + 1);
	ft_check_malloc(data->matrix);
	data->matrix[data->height + 1] = NULL;
	fd = open(s, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = (char *) malloc (sizeof(char) * data->len + 1);
		ft_check_malloc(data->matrix[i]);
		//data->matrix[i][data->len] = '\0';
		line = get_next_line(fd);
		//check_matrix(data->matrix, &flags);
		ft_strlcpy (data->matrix[i], line, data->len);
		i++;
	}
	close (fd);
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
		line = get_next_line(fd);
	}
	close (fd);
	if (data->height < 3 || data->len < 5)
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
	if (check_len(s, data) == 0 || get_matrix(s, data) == 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_sl	data;

	if (argc != 2)
		ft_error("Arg");
	if (get_map(argv[1], &data) == 0)
		ft_error("Map");
}
