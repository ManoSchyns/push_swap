/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 08:28:24 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:15:58 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_base_size(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i ++;
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		count;
	int		base_n;
	char	c;
	long	n;

	base_n = get_base_size(base);
	n = nbr;
	count = 1;
	if (n >= base_n)
		count += ft_putnbr_base(n / base_n, base);
	c = base[n % base_n];
	write (2, &c, 1);
	return (count);
}
