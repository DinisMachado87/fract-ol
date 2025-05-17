/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:30:40 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 19:34:53 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_dig(long n)
{
	char	chr;

	chr = n + '0';
	write(1, &chr, 1);
}

static int	check_positive(long n, int details)
{
	int	n_printed;

	n_printed = 0;
	if (n > 0 && details == '+')
	{
		printf_putchar('+');
		n_printed++;
	}
	else if (n < 0 || (n > 0 && details == '-'))
	{
		printf_putchar('-');
		n_printed++;
	}
	return (n_printed);
}

static int	my_putnum(long n)
{
	int	n_printed;

	n_printed = 0;
	if (n <= 9)
	{
		print_dig(n);
		n_printed++;
	}
	else if (n >= 10)
	{
		n_printed += my_putnum(n / 10);
		n_printed += my_putnum(n % 10);
	}
	return (n_printed);
}

int	printf_putnbr(int n, char details)
{
	int		n_printed;
	long	num;

	num = (long)n;
	n_printed = 0;
	n_printed += check_positive(n, details);
	if (num < 0)
		num = -num;
	n_printed += my_putnum(num);
	return (n_printed);
}

int	printf_putunbr(unsigned int n)
{
	int	n_printed;

	n_printed = my_putnum((long)n);
	return (n_printed);
}
