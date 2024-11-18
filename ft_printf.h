/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:29:22 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/05 11:07:06 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

long	ft_abs(long a);
size_t	ft_strlen(char const *s);
size_t	get_n_len(size_t n, size_t base);
size_t	write_signed(long long n, char make_unsigned);
size_t	write_in_hex(size_t n, char upper, char const *null_str);
size_t	write_str(char const *str, char upper, char dealloc);
size_t	write_str_or_c(va_list args, char is_char);
void	write_until_percent(char const *str, size_t *i, char *finished);
int		ft_printf(char const *str, ...);

#endif
