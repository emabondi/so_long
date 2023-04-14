/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:32:43 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/05 20:43:28 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcpy_gnl(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	return (i);
}

int	ft_strchr_gnl(const char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			break ;
		s++;
	}
	if (*s != c)
		return (0);
	return (1);
}

char	*ft_strdup_gnl(char *str)
{
	size_t	i;
	char	*str2;

	i = ft_strlen_gnl(str);
	str2 = (char *) malloc (sizeof(char) * i + 1);
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strjoin_gnl(char *str, char *buffer)
{
	char	*strunion;
	size_t	len;
	int		i;

	if (str == NULL)
	{
		strunion = ft_strdup_gnl(buffer);
		return (strunion);
	}
	len = ft_strlen_gnl(str) + ft_strlen_gnl(buffer);
	strunion = (char *) malloc (sizeof(char) * len + 1);
	if (!strunion)
		return (NULL);
	i = 0;
	i += ft_strcpy_gnl(strunion, str);
	i += ft_strcpy_gnl(strunion + i, buffer);
	strunion[i] = '\0';
	free (str);
	return (strunion);
}

char	*ft_split_gnl(char *str)
{
	int		i;
	int		j;
	char	*save;	

	if (ft_strchr_gnl(str, '\n') == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	j = 0;
	while (str[i + j] != '\0')
		j++;
	if (j == 0)
		return (NULL);
	save = (char *) malloc (sizeof(char) * j + 1);
	if (!save)
		return (NULL);
	j = 0;
	j += ft_strcpy_gnl(save, str + i);
	save[j] = '\0';
	str[i] = '\0';
	return (save);
}
