/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:40:10 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:55:48 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i_str;
	size_t	i_new_s;
	size_t	limiter;
	char	*new_s;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	limiter = ft_strlen(s) - start; 
	if (len > limiter)
		len = limiter;
	new_s = (char *)malloc((sizeof (char)) * (len + 1));
	if (!new_s)
		return (NULL);
	i_str = start;
	i_new_s = 0;
	while (s[i_str] && i_new_s < len)
	{
		new_s[i_new_s] = s[i_str];
		i_str++;
		i_new_s++;
	}
	new_s[i_new_s] = '\0';
	return (new_s);
}
