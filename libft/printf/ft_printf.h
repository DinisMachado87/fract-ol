/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:51:39 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 19:26:24 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

size_t	printf_strlen(const char *str);
int		printf_putchar(char c);
int		printf_putstr(char *s);
int		printf_putnbr(int n, char details);
int		printf_putunbr(unsigned int n);
int		printf_putbase(uintptr_t n, char form_str);
int		printf_putptr(uintptr_t n, char form_str);
int		ft_printf(const char *form_str, ...);

#endif
