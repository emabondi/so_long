/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:28:04 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/20 22:53:32 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_nate2(t_sl *data, int i, int j)
{
	if (data->nate_dir == 3)
	{
		if (data->frame < 100)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_f1, i * 64, j * 64);
		else if (data->frame < 200)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_f2, i * 64, j * 64);
		else if (data->frame < 300)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_f3, i * 64, j * 64);
	}
	else if (data->nate_dir == 4)
	{
		if (data->frame < 100)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_l1, i * 64, j * 64);
		else if (data->frame < 200)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_l2, i * 64, j * 64);
		else if (data->frame < 300)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_l3, i * 64, j * 64);
	}
}

void	draw_nate(t_sl *data, int i, int j)
{
	if (data->nate_dir == 1)
	{
		if (data->frame < 100)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_b1, i * 64, j * 64);
		else if (data->frame < 200)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_b2, i * 64, j * 64);
		else if (data->frame < 300)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_b3, i * 64, j * 64);
	}
	else if (data->nate_dir == 2)
	{
		if (data->frame < 100)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_r1, i * 64, j * 64);
		else if (data->frame < 200)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_r2, i * 64, j * 64);
		else if (data->frame < 300)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.nate_r3, i * 64, j * 64);
	}
	draw_nate2(data, i, j);
}

void	draw_starly(t_sl *data, int i, int j)
{
	if (data->frame < 50)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fr1, i * 64, j * 64);
	else if (data->frame < 100)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fr2, i * 64, j * 64);
	else if (data->frame < 150)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fr3, i * 64, j * 64);
	else if (data->frame < 200)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fl1, i * 64, j * 64);
	else if (data->frame < 250)
		mlx_put_image_to_window(data->mlx,
			data->window, data->image.starly_fl2, i * 64, j * 64);
	else if (data->frame < 300)
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
		//mlx_put_image_to_window
		//	(data->mlx, data->window, data->image.nate_f1, i * 64, j * 64);
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
	data->frame++;
	if (data->frame == 300)
		data->frame = 1;
	return (0);
}
