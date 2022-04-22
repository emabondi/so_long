/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:00:52 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/22 22:22:47 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_nate(t_sl *data, int i, int j)
{
	if (data->x_nate != -1 && data->y_nate != -1)
		ft_error("Map");
	data->x_nate = j;
	data->y_nate = i;
	data->nate_dir = 3;
	data->pika_dir = 3;
	data->x_pika = -1;
	data->y_pika = -1;
}

void	check_m(t_sl *data, int i, int j)
{
	if ((i == 0 || j == 0 || i == data->height - 1 || j == data->len - 1)
		&& data->matrix[i][j] != '1')
		ft_error("Map");
	if (data->matrix[i][j] != '0' && data->matrix[i][j] != '1' &&
		data->matrix[i][j] != 'P' && data->matrix[i][j] != 'E'
		&& data->matrix[i][j] != 'C' && data->matrix[i][j] != 'N')
		ft_error("Map");
}

void	ft_error(char *str)
{
	ft_printf("%s error\n", str);
	exit (1);
}

void	ft_check_malloc(void *ptr)
{
	if (ptr == NULL)
		ft_error("Malloc");
}
