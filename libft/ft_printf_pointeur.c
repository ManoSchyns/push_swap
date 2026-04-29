/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointeur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 08:28:19 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:16:00 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa_long(unsigned long n)
{
	int		count;
	char	c;
	char	*base;

	base = "0123456789abcdef";
	count = 1;
	if (n >= 16)
		count += ft_puthexa_long(n / 16);
	c = base[n % 16];
	write (2, &c, 1);
	return (count);
}

int	ft_put_pointeur(void *p)
{
	unsigned long	adress;

	if (p == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(2, "0x", 2);
	adress = (unsigned long)p;
	return (2 + ft_puthexa_long(adress));
}
