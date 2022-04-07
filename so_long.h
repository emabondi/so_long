/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:55:19 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/07 17:10:09 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"mylib/ft_printf.h"
# include<stdio.h>
# include<stdlib.h>
# include"mylib/gnl/get_next_line.h"

typedef struct so_long
{
	int		height;
	int		len;
	char	**matrix;
}				t_sl;

typedef struct flags
{
	int	p_flag;
	int	c_flag;
	int	e_flag;
}				t_flags;

void	ft_error(char *str);
void	ft_check_malloc(void *ptr);
void	check_m(t_sl *data, int i, int j);

#endif