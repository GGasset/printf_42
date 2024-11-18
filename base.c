/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:13:46 by ggasset-          #+#    #+#             */
/*   Updated: 2024/10/31 12:45:45 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_abs(long a)
{
	return (a * (1 - 2 * (a < 0)));
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	get_n_len(size_t n, size_t base)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

size_t	write_str(char const *str, char upper, char dealloc)
{
	char	tmp;
	size_t	i;
	size_t	control;

	if (!str)
		return (0);
	control = 0;
	i = 0;
	while (str[i])
	{
		tmp = str[i];
		tmp += ('A' - 'a') * (upper == 1 && tmp >= 'a' && tmp <= 'z');
		tmp += ('a' - 'A') * (!upper && tmp >= 'A' && tmp <= 'Z');
		control += write(1, &tmp, 1) > 0;
		i++;
	}
	if (dealloc)
		free((void *)str);
	return (control);
}
