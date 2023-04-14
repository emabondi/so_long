/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_resolver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:06:45 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/05 17:04:26 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resolver_c(const char *str, char c, t_struct *params)
{
	int	i;

	i = 0;
	i += check_minus(str[i], params);
	params->width = find_wop(str, &i);
	if (!params->minus && params->width > 1)
		write_spaces(params->width - 1, ' ', params);
	write (1, &c, 1);
	params->count += 1;
	if (params->minus && params->width > 1)
		write_spaces(params->width - 1, ' ', params);
}

void	resolver_s(const char *str, char *word, t_struct *params)
{
	int	i;

	if (word == NULL)
	{
		write (1, "(null)", 6);
		params->count += 6;
		return ;
	}
	i = 0;
	params->precision = ft_strlen(word);
	i += check_minus(str[i], params);
	params->width = find_wop(str, &i);
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
		params->precision = find_wop(str + 1, &i);
	else if (str[i] == '.' && !ft_isdigit(str[i + 1]))
		params->precision = 0;
	if (!params->minus && (params->width - params->precision) >= 1)
		write_spaces(params->width - params->precision, ' ', params);
	i = 0;
	while (i < params->precision && word[i] != '\0')
		i += ft_putchar(word[i]);
	params->count += i;
	if (params->minus && (params->width - params->precision) >= 1)
		write_spaces(params->width - params->precision, ' ', params);
}

void	resolver_p(unsigned long i, t_struct *params)
{
	write(1, "0x", 2);
	params->count += 2;
	ft_putnbr_base(i, "0123456789abcdef", params);
}

void	resolver_d(int num, t_struct *params)
{
	char	*box;
	int		i;

	box = ft_itoa(num);
	i = 0;
	while (box[i])
	{
		write (1, &box[i], 1);
		params->count += 1;
		i++;
	}
	free (box);
}

void	resolver_u(int num, t_struct *params)
{
	char			*box;
	int				i;
	unsigned int	x;

	x = (unsigned int) num;
	box = ft_itoa(num);
	i = 0;
	while (box[i])
	{
		write (1, &box[i], 1);
		params->count += 1;
		i++;
	}
	free (box);
}
