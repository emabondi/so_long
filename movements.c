/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:16:33 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/20 23:50:34 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_sl *data)
{
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	else if (keycode == 2)
	{
		if ()
			;
	}
	return (0);
}
