/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:46:59 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:53:35 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t memcount, size_t size)
{
	unsigned char	*arr;
	size_t			i_mem;

	i_mem = 0;
	arr = malloc(memcount * size);
	if (!arr)
		return (NULL);
	while (i_mem < memcount * size)
	{
		arr[i_mem] = 0;
		i_mem++;
	}
	return (arr);
}
