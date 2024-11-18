/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:18:35 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/06 12:32:53 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	write_signed(long long n, char make_unsigned)
{
	char	*output;
	size_t	n_len;
	char	negative;
	size_t	i;

	if (make_unsigned)
		n = (unsigned int)n;
	if (!n)
		return (write_str("0", 2, 0));
	n_len = get_n_len(ft_abs(n), 10);
	negative = n < 0;
	output = malloc(n_len + negative + 1);
	if (output)
		output[n_len + negative] = 0;
	if (output && negative)
		output[0] = '-';
	i = n_len + negative - 1;
	while (n && output)
	{
		output[i] = ft_abs((long)(n - n / 10 * 10)) + '0';
		i--;
		n /= 10;
	}
	return (write_str(output, 2, 1));
}

size_t	write_in_hex(size_t n, char upper, char const *null_str)
{
	char	*to_write;
	size_t	n_len;
	size_t	tmp;
	size_t	i;

	n_len = get_n_len(n, 16);
	if (!n_len)
	{
		return (write_str(null_str, 2, 0));
	}
	to_write = malloc(n_len + 1);
	if (to_write)
		to_write[n_len] = 0;
	i = 0;
	while (n && to_write)
	{
		tmp = n - n / 16 * 16;
		tmp += '0' * (tmp < 10) + ('A' - 10) * (tmp >= 10);
		to_write[n_len - i - 1] = tmp;
		n /= 16;
		i++;
	}
	return (write_str(to_write, upper, 1));
}

size_t	write_str_or_c(va_list args, char is_char)
{
	char	*arg;
	char	arg_c;

	if (is_char)
	{
		arg_c = (char)va_arg(args, int);
		return (write(1, &arg_c, 1) > 0);
	}
	else
	{
		arg = va_arg(args, char *);
		arg += (size_t)"(null)" * (!arg);
		return (write_str(arg, 2, 0));
	}
}

void	write_until_percent(char const *str, size_t *i, char *finished)
{
	while (str[*i] && str[*i] != '%')
	{
		write(1, &str[*i], 1);
		(*i)++;
	}
	*finished = str[*i] == 0;
}
