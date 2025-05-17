/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:43:20 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:54:43 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n)
{
	size_t	n_len;

	n_len = 0;
	if (n <= 0)
	{
		n_len++;
		n = -n;
	}
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static void	rec_itoa(long num, size_t n_len, char *str_result)
{
	if (num < 0)
	{
		str_result[0] = '-';
		rec_itoa(-num, (n_len - 1), str_result + 1);
	}
	else if (num >= 10)
	{
		rec_itoa(num / 10, (n_len - 1), str_result);
		str_result[n_len] = (num % 10) + '0';
	}
	else
	{
		str_result[n_len] = num + '0';
		return ;
	}
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*str_result;

	n_len = num_len((long)n);
	str_result = (char *)malloc((n_len + 1) * sizeof(char));
	if (!str_result)
		return (NULL);
	str_result[n_len] = '\0';
	rec_itoa((long)n, n_len - 1, str_result);
	return (str_result);
}
