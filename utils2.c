/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:16:05 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/27 19:13:45 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	free_and_exit(t_sl *data, char *str)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	ft_printf("%s\n", str);
	exit (1);
}

void	ft_draw2(t_sl *data)
{
	char	*str;

	mlx_string_put(data->mlx, data->window, 0, 16, 0x000000, "Moves: ");
	str = ft_itoa(data->m);
	mlx_string_put(data->mlx, data->window, 68, 16, 0x000000, str);
	free(str);
	data->frame++;
	if (data->frame == 210)
		data->frame = 1;
}
