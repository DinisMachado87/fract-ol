/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:56 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:54:43 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_src;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i_src = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i_src] && i_src + dest_len < size - 1)
	{
		dst[i_src + dest_len] = src[i_src];
		i_src++;
	}
	dst[i_src + dest_len] = '\0';
	return (src_len + dest_len);
}
