/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:09:04 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:59:46 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i_end;
	size_t	len;
	size_t	i_new_str;
	char	*new_str;

	if (s1[0] == '\0')
		return (ft_strdup(""));
	i_start = 0;
	while (s1[i_start] && is_set(s1[i_start], set))
		i_start++;
	i_end = ft_strlen(s1) - 1;
	while (i_end > i_start && is_set(s1[i_end], set))
		i_end--;
	len = i_end - i_start + 1;
	if (len <= 0)
		return (ft_strdup(""));
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i_new_str = 0;
	while (i_start <= i_end)
		new_str[i_new_str++] = s1[i_start++];
	new_str[i_new_str] = '\0';
	return (new_str);
}
