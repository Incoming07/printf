/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:24:11 by bglover           #+#    #+#             */
/*   Updated: 2019/07/25 15:32:46 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../GNL/libft/libft.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
				ft_putnbr(va_arg(ap, int));//нужен лонг инт
			if (format[i] == 'c')
				ft_putchar(va_arg(ap, int));
			if (format[i] == 's')
				ft_putstr(va_arg(ap, char *));
			if (format[i] == '%')
				write(1, &format[i], 1);
			i++;
		}
		else
			write(1, &format[i++], 1);
	}
	return (0);
}

int		main(void)
{
//	int		a = 1;
//	char	*b = "abc";

//	ft_printf("%d", a);
//	ft_printf("%s", b);
	ft_printf("%0d%d%d%d%d",	1, -2, 3, -4, 5);
	write(1, "\n", 1);
	printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	return (0);
}
