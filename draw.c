/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:28:04 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/26 18:53:22 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_nate2(t_sl *data, int i, int j)
{
	if (data->nate_dir == 3)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_f1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_f2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_f3, i * 64, j * 64);
	}
	else if (data->nate_dir == 4)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_l1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_l2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_l3, i * 64, j * 64);
	}
}

void	draw_nate(t_sl *data, int i, int j)
{
	if (data->nate_dir == 1)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_b1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_b2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_b3, i * 64, j * 64);
	}
	else if (data->nate_dir == 2)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_r1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_r2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_r3, i * 64, j * 64);
	}
	draw_nate2(data, i, j);
}

void	draw_starly(t_sl *data, int i, int j)
{
	if (data->frame < 35)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fr1, i * 64, j * 64);
	else if (data->frame < 70)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fr2, i * 64, j * 64);
	else if (data->frame < 105)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fr3, i * 64, j * 64);
	else if (data->frame < 140)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fl1, i * 64, j * 64);
	else if (data->frame < 175)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fl2, i * 64, j * 64);
	else if (data->frame < 210)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fl3, i * 64, j * 64);
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
		draw_nate(data, i, j);
	else if (c == 'N')
		draw_starly(data, i, j);
}

int	ft_draw(t_sl *data)
{
	int		i;
	int		j;

	mlx_clear_window(data->mlx, data->window);
	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			if (j == data->y_pika && i == data->x_pika)
				draw_pika(data, j, i);
			else
				put_image(data, data->matrix[j][i], j, i);
			i++;
		}
		j++;
	}
	ft_draw2(data);
	return (0);
}
