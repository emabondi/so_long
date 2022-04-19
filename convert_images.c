/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:04:43 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/19 20:24:23 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_images_4(t_sl *data)
{
	data->image.nate_l3 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_l3.xpm", &data->x, &data->x);
	data->image.nate_r1 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_r1.xpm", &data->x, &data->x);
	data->image.nate_r2 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_r2.xpm", &data->x, &data->x);
	data->image.nate_r3 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_r3.xpm", &data->x, &data->x);
	data->image.pikachu_br2 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_br_2.xpm", &data->x, &data->x);
	data->starly_frame = 1;
}

void	convert_images_3(t_sl *data)
{
	data->image.starly_br3 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_br_3.xpm", &data->x, &data->x);
	data->image.starly_bl1 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_bl_1.xpm", &data->x, &data->x);
	data->image.starly_bl2 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_bl_2.xpm", &data->x, &data->x);
	data->image.starly_bl3 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_bl_3.xpm", &data->x, &data->x);
	data->image.nate_b1 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_b1.xpm", &data->x, &data->x);
	data->image.nate_b2 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_b2.xpm", &data->x, &data->x);
	data->image.nate_b3 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_b3.xpm", &data->x, &data->x);
	data->image.nate_f1 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_f1.xpm", &data->x, &data->x);
	data->image.nate_f2 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_f2.xpm", &data->x, &data->x);
	data->image.nate_f3 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_f3.xpm", &data->x, &data->x);
	data->image.nate_l1 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_l1.xpm", &data->x, &data->x);
	data->image.nate_l2 = mlx_xpm_file_to_image
		(data->mlx, "./img/nate_l2.xpm", &data->x, &data->x);
	convert_images_4(data);
}

void	convert_images_2(t_sl *data)
{
	data->image.pikachu_br3 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_br_3.xpm", &data->x, &data->x);
	data->image.pikachu_bl1 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_bl_1.xpm", &data->x, &data->x);
	data->image.pikachu_bl2 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_bl_2.xpm", &data->x, &data->x);
	data->image.pikachu_bl3 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_bl_3.xpm", &data->x, &data->x);
	data->image.starly_fl1 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_fl_1.xpm", &data->x, &data->x);
	data->image.starly_fl2 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_fl_2.xpm", &data->x, &data->x);
	data->image.starly_fl3 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_fl_3.xpm", &data->x, &data->x);
	data->image.starly_fr1 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_fr_1.xpm", &data->x, &data->x);
	data->image.starly_fr2 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_fr_2.xpm", &data->x, &data->x);
	data->image.starly_fr3 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_fr_3.xpm", &data->x, &data->x);
	data->image.starly_br1 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_br_1.xpm", &data->x, &data->x);
	data->image.starly_br2 = mlx_xpm_file_to_image
		(data->mlx, "./img/starly_br_2.xpm", &data->x, &data->x);
	convert_images_3(data);
}

void	convert_images(t_sl *data)
{
	data->x = 64;
	data->image.tree = mlx_xpm_file_to_image
		(data->mlx, "./img/tree.xpm", &data->x, &data->x);
	data->image.grass = mlx_xpm_file_to_image
		(data->mlx, "./img/grass.xpm", &data->x, &data->x);
	data->image.masterball = mlx_xpm_file_to_image
		(data->mlx, "./img/masterball.xpm", &data->x, &data->x);
	data->image.exit = mlx_xpm_file_to_image
		(data->mlx, "./img/exit.xpm", &data->x, &data->x);
	data->image.pikachu_fl1 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_fl_1.xpm", &data->x, &data->x);
	data->image.pikachu_fl2 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_fl_2.xpm", &data->x, &data->x);
	data->image.pikachu_fl3 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_fl_3.xpm", &data->x, &data->x);
	data->image.pikachu_fr1 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_fr_1.xpm", &data->x, &data->x);
	data->image.pikachu_fr2 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_fr_2.xpm", &data->x, &data->x);
	data->image.pikachu_fr3 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_fr_3.xpm", &data->x, &data->x);
	data->image.pikachu_br1 = mlx_xpm_file_to_image
		(data->mlx, "./img/pikachu_br_1.xpm", &data->x, &data->x);
	convert_images_2(data);
}
