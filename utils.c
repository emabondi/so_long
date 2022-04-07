/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:00:52 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/07 17:09:41 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_m(t_sl *data, int i, int j)
{
	if ((i == 0 || j == 0 || i == data->height - 1 || j == data->len - 1)
		&& data->matrix[i][j] != '1')
		ft_error("Map");
	if (data->matrix[i][j] != '0' && data->matrix[i][j] != '1' &&
		data->matrix[i][j] != 'P' && data->matrix[i][j] != 'E'
		&& data->matrix[i][j] != 'C')
		ft_error("Map");
}

void	ft_error(char *str)
{
	ft_printf ("%s error\n", str);
	exit (1);
}

void	ft_check_malloc(void *ptr)
{
	if (ptr == NULL)
		ft_error("Malloc");
}
