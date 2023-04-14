/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:22:18 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/05 20:42:53 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*str;
	char		*buffer;
	int			bytes;

	str = save;
	bytes = 1;
	if (fd < 0 || fd > 256)
		return (NULL);
	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr_gnl(str, '\n') == 0 && bytes > 0)
	{
		bytes = read (fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		str = ft_strjoin_gnl(str, buffer);
		if (bytes < BUFFER_SIZE)
			bytes = 0;
	}
	free (buffer);
	save = ft_split_gnl(str);
	return (str);
}

size_t	ft_strlen_gnl(char const *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//int	main()
//{
//	char *file_name;
//	int	fd;

//	fd = open("file.txt" , O_RDONLY);
//	printf("result:%s", get_next_line(fd));
//	printf("result:%s", get_next_line(fd));
//	printf("result:%s", get_next_line(fd));
//	close (fd);
//}