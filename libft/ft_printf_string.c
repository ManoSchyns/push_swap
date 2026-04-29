/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:24:13 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:16:02 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	if (str == NULL)
	{
		write (2, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		write (2, str + i, 1);
		i ++;
	}
	return (i);
}
