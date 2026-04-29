/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:24:11 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:16:04 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(const char *str);
int	ft_put_pointeur(void *p);
int	ft_parsing(const char *format, va_list *args);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr(int nbr);
int	ft_putchar(int c);
int	ft_unsigned_putnbr(unsigned int nbr);

#endif