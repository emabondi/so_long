/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:55:19 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/26 21:09:44 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"mylib/ft_printf.h"
# include<stdio.h>
# include<stdlib.h>
# include"mylib/gnl/get_next_line.h"
# include<mlx.h>

typedef struct s_image
{
	void	*tree;
	void	*grass;
	void	*exit;
	void	*masterball;
	void	*pikachu_fl1;
	void	*pikachu_fl2;
	void	*pikachu_fl3;
	void	*pikachu_fr1;
	void	*pikachu_fr2;
	void	*pikachu_fr3;
	void	*pikachu_br1;
	void	*pikachu_br2;
	void	*pikachu_br3;
	void	*pikachu_bl1;
	void	*pikachu_bl2;
	void	*pikachu_bl3;
	void	*starly_fl1;
	void	*starly_fl2;
	void	*starly_fl3;
	void	*starly_fr1;
	void	*starly_fr2;
	void	*starly_fr3;
	void	*nate_b1;
	void	*nate_b2;
	void	*nate_b3;
	void	*nate_f1;
	void	*nate_f2;
	void	*nate_f3;
	void	*nate_l1;
	void	*nate_l2;
	void	*nate_l3;
	void	*nate_r1;
	void	*nate_r2;
	void	*nate_r3;
}			t_image;

typedef struct so_long
{
	int		x;
	int		height;
	int		len;
	int		x_nate;
	int		y_nate;
	int		n_collectibles;
	int		e_flag;
	char	**matrix;
	void	*mlx;
	void	*window;
	int		frame;
	int		nate_dir;
	int		x_pika;
	int		y_pika;
	int		pika_dir;
	int		m;
	t_image	image;
}				t_sl;

void	ft_error(char *str);
void	ft_check_malloc(void *ptr);
void	check_m(t_sl *data, int i, int j);
void	convert_images(t_sl *data);
int		ft_draw(t_sl *data);
int		key_handler(int keycode, t_sl *data);
void	get_nate(t_sl *data, int x, int y);
void	draw_pika(t_sl *data, int j, int i);
void	draw_pika2(t_sl *data, int j, int i);
void	ft_draw2(t_sl *data);
void	free_and_exit(t_sl *data, char *str);
void	endgame(t_sl *data, char *str);

#endif