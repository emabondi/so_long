/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:28:04 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/19 20:38:12 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_starly(t_sl *data, int i, int j)
{
	if (data->starly_frame == 1)
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.starly_fr1, i * 64, j * 64);
	else if (data->starly_frame == 2)
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.starly_fr2, i * 64, j * 64);
	else if (data->starly_frame == 3)
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.starly_fr3, i * 64, j * 64);
}

void	put_image(t_sl *data, char c, int j, int i)
{
	if (c == '1')
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.tree, i * 64, j * 64);
	else if (c == '0')
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.grass, i * 64, j * 64);
	else if (c == 'C')
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.masterball, i * 64, j * 64);
	else if (c == 'E')
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.exit, i * 64, j * 64);
	else if (c == 'P')
		mlx_put_image_to_window
			(data->mlx, data->window, data->image.nate_f1, i * 64, j * 65);
	else if (c == 'N')
		draw_starly(data, i, j);
		//mlx_put_image_to_window
		//	(data->mlx, data->window, data->image.starly_fr1, i * 64, j * 64);
}

int	ft_draw(t_sl *data)
{
	int	i;
	int	j;

	mlx_clear_window(data->mlx, data->window);
	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			put_image(data, data->matrix[j][i], j, i);
			i++;
		}
		j++;
	}
	data->starly_frame++;
	if (data->starly_frame == 4)
		data->starly_frame = 1;
	return (0);
}
