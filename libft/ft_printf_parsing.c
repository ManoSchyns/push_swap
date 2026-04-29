/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:55:19 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:15:59 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_in_set(int c)
{
	int		i;
	char	*set;

	set = "cspdiuxX%";
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static int	apply_format(int c, va_list *elem)
{
	if (c == 's')
		return (ft_putstr(va_arg(*elem, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*elem, int)));
	else if (c == 'p')
		return (ft_put_pointeur(va_arg(*elem, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*elem, int)));
	else if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(*elem, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*elem, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*elem, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_parsing(const char *format, va_list *args)
{
	int	i;
	int	printed_count;

	i = 0;
	printed_count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && is_in_set(format[i + 1]))
		{
			printed_count += apply_format(format[i + 1], args);
			i += 1;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			printed_count += ft_putchar(format[i]);
		else if (format[i] == '%')
		{
			printed_count += ft_putchar(format[i + 1]);
			i += 1;
		}
		else
			printed_count += ft_putchar(format[i]);
		i ++;
	}
	return (printed_count);
}
