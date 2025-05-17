/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:48:08 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 19:35:18 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	printf_strlen(const char *str)
{
	size_t	i_ltr;

	i_ltr = 0;
	while (str[i_ltr])
		i_ltr++;
	return (i_ltr); 
}
