/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:25:06 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/05 20:45:53 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *s)
{
	char	*str;
	int		len;
	int		c_flag;
	int		p_flag;
	int		e_flag;

	c_flag = 0;
	p_flag = 0;
	e_flag = 0;
	str = get_next_line();
	len = ft_strlen(str);
	while (str != NULL)
	{
		get_next_line();
	}
	return (1);
}

int	get_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i < 4 || s[i - 4] != '.' || s[i - 3] != 'b'
		|| s[i - 2] != 'e' || s[i - 1] != 'r')
		return (0);
	if (check_map(s) == 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		ft_error("Arg");
	if (get_map(argv[1]) == 0)
		ft_error("Map");
}
