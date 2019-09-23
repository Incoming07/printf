/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:41:20 by bglover           #+#    #+#             */
/*   Updated: 2019/08/17 15:42:52 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"


/**
 * объединение для определения бинарного представления числа побитовым сдвигом
 **/

union union_1
{
	long double i;
	short 		c[5];
};

/**
 * определение мантиссы
 **/

void make_man(int man[])
{
	int i;
	int j;

	i = 63;
	while (i > 0)
	{
		if (man[i] == 0)
			man[i--] = '\0';
		else
			break;
		
	}
	j = 0;
	write(1, "\nМантисса: ", 19);
	while (j <= i)
		ft_putnbr(man[j++]);
}

/**
 * определение порядка в 10-ой системе
 **/

int make_por(int por[])
{
	int		i;
	int		j;
	int		k;
	short	digit;

	i = 14;
	j = -1;
	k = 0;
	digit = 0;
	while (i > 0)
	{
		if (por[i] == 0 || (i == 15 && por[i] == 1))
			j++;
		else if (i != 15 && por[i] == 1) 
		{
			j++;
			while (k < j)
			{
				por[i] *= 2;
				k++;
			}
			k = 0;
		}
		i--;
	}
	i = 0;
	write (1, "\n", 1);
	while (i <= 14)
	{
		ft_putnbr(por[i++]);
		write (1, " ", 1);
	}
	i = 0;
	while (i < 15)
		digit += por[i++];
	write(1, "\nПорядок:  ", 18);
	digit -= 16383;
	ft_putnbr(digit);
	return(digit);
}

/**
 * выделене знака, порядка и мантиссы
 **/

int find_numb(char bin_numb[])
{
	int		i;
	int		j;
	int	sign;
	int	por[15];
	int	man[64];

	i = 0;
	j = 0;
	while (i < 80)
	{
		if (i == 0)
			sign = bin_numb[i];
		else if (i < 16)
			por[j++] = bin_numb[i];
		else
		{
			if (i == 16)
				j = 0;
			man[j++] = bin_numb[i];
		}
		i++;
	}
	printf("Знак:     %d\n", sign);
	write(1, "Порядок:  ", 17);
	i = 0;
	while (i < 15)
		ft_putnbr(por[i++]);
	//write(1, "\n", 1);
	//write(1, "Мантисса: ", 19);
	//i = 0;
	//while (i < 52)
	//	ft_putnbr(man[i++]);
	//write(1, "\nЧисло: ", 14);
	//write(1, "1.", 2);
	make_man(man);
	//write(1, "e", 2);
	return (make_por(por));	
}

/**
 * запись числа в двоичном виде в массив
 **/

int printBits(size_t const size, void const * const ptr)
{
	unsigned char	*b; 
	unsigned char	byte;
	int			i;
	int			j;
	int			bits;
	char			bin_numb[80];
	int			bn;
	
	bn = 0;
	bits = 0;
	b = (unsigned char*) ptr;
	i = size - 1;
	j = 7;
    printf("sizeof = %zu \n",size);
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			bin_numb[bn++] = byte;
			printf("%u", byte);
            bits++;
			j--;
		}
		printf(" ");
		i--;
	}
    printf("\nbits = %d \n", bits);
	return (find_numb(bin_numb));
}

int print_double(double db)
{
	//double db = 0.15625;
	printf("\nЧисло %.5f\n", db);
	union union_1 un;
	un.i = db;
	printf("\n");
	return (printBits(sizeof(un.c), &un.i));
}
/*  for (i=size-1;i>=0;i--)
    {
        //printf("\n");
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
            bits++;
        }
	}*/