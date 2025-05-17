/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:01:57 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:55:04 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *needle, size_t len)
{
	size_t	i_char;
	size_t	i_needle;

	i_char = 0;
	if (needle[0] == '\0')
		return ((char *)big);
	while (i_char < len && big[i_char] != '\0')
	{
		i_needle = 0;
		if (big[i_char] == needle[i_needle])
		{
			while (i_char + i_needle < len
				&& big[i_char + i_needle] == needle[i_needle]
				&& needle[i_needle] != '\0')
				i_needle++;
			if (needle[i_needle] == '\0')
				return ((char *)big + i_char);
		}
		i_char++;
	}
	return (NULL);
}
