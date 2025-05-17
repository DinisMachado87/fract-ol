/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:28:46 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:54:43 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i_str;

	i_str = 0;
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i_str])
	{
		newstr[i_str] = s1[i_str];
		i_str++;
	}
	while (s2[i_str - ft_strlen(s1)])
	{
		newstr[i_str] = s2[i_str - ft_strlen(s1)];
		i_str++;
	}
	newstr[i_str] = '\0';
	return (newstr);
}
