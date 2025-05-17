/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:45:01 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/03 18:01:04 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i_mem;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i_mem = 0;
	if (dest < src)
	{
		while (i_mem < n)
		{
			ptr_dest[i_mem] = ptr_src[i_mem];
			i_mem++;
		}
	}
	else if (dest > src)
	{
		while (n--)
			ptr_dest[n] = ptr_src[n];
	}
	return (dest);
}
