/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:24:11 by bglover           #+#    #+#             */
/*   Updated: 2019/07/18 20:51:09 by bglover          ###   ########.fr       */
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
	int		a;
	char	*b;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (format[i] == ' ')
			write(1, &format[i++], 1);
		else
		{
			i++;
			if (format[i] == 'd')
			{
				a = va_arg(ap, int);
				ft_putnbr(a);
			}
			if (format[i] == 'c')
			{
				a = va_arg(ap, int);
				ft_putchar(a);
			}
			if (format[i] == 's')
			{
				b = va_arg(ap, char *);
				ft_putstr(b);
			}
		}
	}
	return (0);
}

int		main(void)
{
	ft_printf("%d %c %s", 10, 'a', "abc");
	printf("%d", 10);
	return (0);
}
