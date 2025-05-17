/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:28:12 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 19:38:57 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	core_putbase(uintptr_t n, char *base)
{
	int		n_printed;
	size_t	base_len;

	n_printed = 0;
	base_len = printf_strlen(base);
	if (n < (uintptr_t)base_len)
	{
		write(1, &base[n], 1);
		n_printed++;
	}
	else
	{
		n_printed += core_putbase((n / base_len), base);
		n_printed += core_putbase((n % base_len), base);
	}
	return (n_printed);
}

int	printf_putptr(uintptr_t n, char form_str)
{
	int	n_printed;

	n_printed = 0;
	if (!n)
		return (printf_putstr("(nil)"));
	n_printed += printf_putstr("0x");
	n_printed += printf_putbase(n, form_str);
	return (n_printed);
}

int	printf_putbase(uintptr_t n, char form_str)
{
	int		n_printed;
	char	*base;

	n_printed = 0;
	if (form_str == 'X')
		base = "0123456789ABCDEF"; 
	else
		base = "0123456789abcdef";
	n_printed += core_putbase(n, base);
	return (n_printed);
}
