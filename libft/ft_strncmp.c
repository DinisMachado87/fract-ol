/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:33:21 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:55:04 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i_str;

	i_str = 0;
	while ((s1[i_str] || s2[i_str]) && i_str < n)
	{
		if (s1[i_str] != s2[i_str])
			return ((unsigned char)s1[i_str] - (unsigned char)s2[i_str]);
		i_str++;
	}
	return (0);
}
