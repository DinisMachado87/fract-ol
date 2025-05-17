/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:42:18 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 19:34:39 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Prints a char and returns the print count.
int	printf_putchar(char c)
{
	int	n_printed;

	n_printed = 1;
	write(1, &c, 1);
	return (n_printed);
}
