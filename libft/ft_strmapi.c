/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:43:08 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:55:04 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i_str;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	i_str = 0;
	new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s[i_str])
	{
		new_str[i_str] = f(i_str, s[i_str]);
		i_str++;
	}
	new_str[i_str] = '\0';
	return (new_str);
}
