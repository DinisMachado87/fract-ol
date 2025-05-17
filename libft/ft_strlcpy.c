/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:54:17 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:53:35 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i_ltr;
	size_t	len;

	len = ft_strlen(src);
	i_ltr = 0;
	if (size > 0)
	{
		while (src[i_ltr] && i_ltr < size - 1)
		{
			dst[i_ltr] = src[i_ltr];
			i_ltr++;
		}
		dst[i_ltr] = '\0';
	}
	return (len);
}
