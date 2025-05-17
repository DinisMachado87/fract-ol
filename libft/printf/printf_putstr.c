/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:59:41 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 19:35:05 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putstr(char *s)
{
	int	n_printed;

	n_printed = 0;
	if (!s)
		return (printf_putstr("(null)"));
	while (s[n_printed])
		n_printed += write(1, &s[n_printed], 1);
	return (n_printed);
}
