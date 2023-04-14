/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_resolver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:32:47 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/31 17:38:34 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_spaces(int len, char c, t_struct *params)
{
	while (len > 0)
	{
		write(1, &c, 1);
		params->count += 1;
		len--;
	}
}

int	find_wop(const char *str, int *j)
{
	int	i;
	int	wop;

	i = *j;
	wop = 0;
	while (ft_isdigit(str[i]))
	{
		wop *= 10;
		wop += str[i] - '0';
		i++;
	}
	*j = i;
	return (wop);
}

int	check_minus(char c, t_struct *params)
{
	if (c == '-')
	{
		params->minus = 1;
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(unsigned long nbr, char *base, t_struct *params)
{
	size_t			lbase;
	unsigned long	nb;

	lbase = 0;
	nb = nbr;
	if (nb < 0)
	{
		params->count += ft_putchar('-');
		nb *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nb < lbase)
		params->count += ft_putchar(base[nb]);
	if (nb >= lbase)
	{
		ft_putnbr_base(nb / lbase, base, params);
		ft_putnbr_base(nb % lbase, base, params);
	}
}

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}
