/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:55 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/06 17:48:30 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex(char option, va_list args)
{
	size_t	tmp;
	size_t	tmp2;
	size_t	null;
	char	upper;
	char	is_addr;

	null = (size_t)"0";
	null += ((size_t)"(nil)" - null) * (option == 'p');
	if (option == 'p')
		tmp = (size_t)va_arg(args, void *);
	else
		tmp = (size_t)va_arg(args, unsigned int);
	upper = option == 'X';
	is_addr = option == 'p';
	tmp2 = (write(1, "0x", 2 * is_addr * (tmp != 0)) > 0) * 2;
	return (tmp2 + write_in_hex(tmp, upper, (char const *)null));
}

static size_t	text(char option, va_list args)
{
	if (option == 'c' || option == 's')
		return (write_str_or_c(args, option == 'c'));
	if (option != '%')
		return (0);
	return (write(1, "%", 1) > 0);
}

static void	route_percent(char *str, size_t *i, size_t *n, va_list args)
{
	size_t	written;
	char	option;
	int		tmp2;

	++*i;
	if (!str[*i])
		return ;
	option = str[*i];
	written = 0;
	if (option == 'c' || option == 's' || option == '%')
		written = text(option, args);
	else if (option == 'p' || option == 'x' || option == 'X')
		written = hex(option, args);
	else if (option == 'i' || option == 'd' || option == 'u')
	{
		if (option == 'u')
			tmp2 = (int)va_arg(args, unsigned int);
		else
			tmp2 = va_arg(args, int);
		written = write_signed((long long)tmp2, option == 'u');
	}
	++*i;
	*n += written;
}

int	ft_printf(char const *str, ...)
{
	size_t	param_count;
	size_t	i;
	size_t	n;
	char	finished;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	finished = 0;
	n = 0;
	param_count = 0;
	i = 0;
	while (!finished)
	{
		write_until_percent(str, &i, &finished);
		if (finished)
			break ;
		route_percent((char *)str, &i, &n, args);
		param_count++;
	}
	va_end(args);
	return (i - param_count * 2 + n);
}

int	main(void)
{
	ft_printf("%K");
	printf("%K");
	/*ft_printf("%i %d %u\n", 0, 0, 0);
	ft_printf("Hola que tal%K\n");
	printf("Hola%");
	printf("\n");
	ft_printf("putnero: %p\n", NULL);
	ft_printf("putnero: %s\n", NULL);
	printf("putnero: %s\n", (char *)NULL);
	ft_printf("Perico: %u\n", -1);
	ft_printf("%i\n", -35);
	ft_printf("%x\n", 255);
	ft_printf("%u %i %d %x %X\n", 35, -35, 35, 255, 255);
	ft_printf("%x %X %p\n", 0, 0, 0);
	ft_printf("%%\n");
	ft_printf("%i\n", -2147483648);
	int a = 0;
	ft_printf("%p | ", &a);
	printf("%p\n", &a);*/
}
