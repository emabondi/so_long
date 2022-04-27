/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:16:33 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/27 18:59:43 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pika2(t_sl *data, int j, int i)
{
	if (data->pika_dir == 3)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_fl1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_fl2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_fl3, i * 64, j * 64);
	}
	if (data->pika_dir == 4)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_bl1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_bl2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_bl3, i * 64, j * 64);
	}
}

void	draw_pika(t_sl *data, int j, int i)
{
	if (data->pika_dir == 1)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_br1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_br2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_br3, i * 64, j * 64);
	}
	if (data->pika_dir == 2)
	{
		if (data->frame < 70)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_fr1, i * 64, j * 64);
		else if (data->frame < 140)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_fr2, i * 64, j * 64);
		else if (data->frame < 210)
			mlx_put_image_to_window(data->mlx,
				data->window, data->image.pikachu_fr3, i * 64, j * 64);
	}
	draw_pika2(data, j, i);
}

void	ft_swap(t_sl *data, int x, int y, int flag)
{
	data->m++;
	data->matrix[data->y_nate][data->x_nate] = '0';
	data->matrix[y][x] = 'P';
	data->pika_dir = data->nate_dir;
	data->x_pika = data->x_nate;
	data->y_pika = data->y_nate;
	data->x_nate = x;
	data->y_nate = y;
	if (flag == 1)
		data->n_collectibles--;
}

void	check_movement(t_sl *data, int x, int y, int dir)
{
	int	flag;

	flag = 0;
	if (data->matrix[y][x] == 'C')
		flag = 1;
	data->nate_dir = dir;
	if (data->matrix[y][x] != '1')
	{
		if (data->matrix[y][x] == 'C' || data->matrix[y][x] == '0')
			ft_swap(data, x, y, flag);
		else if (data->matrix[y][x] == 'N')
			free_and_exit(data, "YOU LOSE");
		else if (data->matrix[y][x] == 'E' && data->n_collectibles == 0)
		{
			ft_swap(data, x, y, flag);
			free_and_exit(data, "YOU WIN");
		}
	}
}

int	key_handler(int keycode, t_sl *data)
{
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		free_and_exit(data, "EXIT");
	}
	else if (keycode == 13)
		check_movement(data, data->x_nate, (data->y_nate - 1), 1);
	else if (keycode == 2)
		check_movement(data, (data->x_nate + 1), data->y_nate, 2);
	else if (keycode == 1)
		check_movement(data, data->x_nate, (data->y_nate + 1), 3);
	else if (keycode == 0)
		check_movement(data, (data->x_nate - 1), data->y_nate, 4);
	return (0);
}
