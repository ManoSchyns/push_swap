/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:23:32 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:40:53 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	n;
	char	c;
	int		add;

	add = 1;
	n = (long) nbr;
	if (n < 0)
	{
		n *= -1;
		write (2, "-", 1);
		add += 1;
	}
	if (n >= 10)
		add += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (2, &c, 1);
	return (add);
}

int	ft_unsigned_putnbr(unsigned int nbr)
{
	char	c;
	int		add;

	add = 1;
	if (nbr >= 10)
		add += ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write (2, &c, 1);
	return (add);
}
