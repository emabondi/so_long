/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:26:42 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/31 17:41:48 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_struct *params)
{
	params->minus = 0;
	params->zero = 0;
	params->hash = 0;
	params->space = 0;
	params->plus = 0;
	params->width = 0;
	params->precision = 0;
}

int	ft_checkidentifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_resolver(const char *str, va_list arg, t_struct *params)
{
	int	i;

	i = 0;
	while (!ft_checkidentifier(str[i]))
		i++;
	if (str[i] == 'c')
		resolver_c(str, va_arg(arg, int), params);
	else if (str[i] == 's')
		resolver_s(str, va_arg(arg, char *), params);
	else if (str[i] == 'p')
		resolver_p(va_arg(arg, unsigned long), params);
	else if (str[i] == 'd')
		resolver_d(va_arg(arg, int), params);
	else if (str[i] == 'i')
		resolver_d(va_arg(arg, int), params);
	else if (str[i] == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", params);
	else if (str[i] == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", params);
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", params);
	else if (str[i] == '%')
		params->count += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	t_struct	params;

	va_start(arg, str);
	i = 0;
	params.count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_struct_init(&params);
			i += ft_resolver((str + i + 1), arg, &params);
			i++;
		}
		else
		{
			write (1, str + i, 1);
			params.count += 1;
		}
		i++;
	}
	return (params.count);
}

//
//int	main()
//{
//	char		c;
//	char		*str;
//	long long	i;
//
//	c = 'A';
//	str = "ciao";
//	i = 0;
//	//printf("%c\n", '0');
//	//ft_printf("%c\n", '0');
//	//printf("\nPC return:%d", printf("PC :%s%", str));
//	printf("\nMIOreturn:%d", ft_printf("MIO:%s", str));
//}
