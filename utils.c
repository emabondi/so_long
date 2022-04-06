/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:00:52 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/06 19:21:36 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
