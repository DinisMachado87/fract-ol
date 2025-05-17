/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:21:35 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:54:43 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i_str;

	i_str = 0;
	if (!s || !f)
		return ;
	while (s[i_str])
	{
		f(i_str, &s[i_str]);
		i_str++;
	}
}
