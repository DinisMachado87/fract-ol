/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:34:44 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/28 20:53:32 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i_mem;
	unsigned char	*str;

	str = (unsigned char *)s;
	i_mem = 0;
	while (i_mem < n)
	{
		if (str[i_mem] == (unsigned char)c)
			return ((void *)&str[i_mem]);
		i_mem++;
	}
	return (NULL);
}
