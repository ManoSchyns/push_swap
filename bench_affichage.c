/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_affichage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:58:14 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:41:10 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_tab (int *tab)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < TAB_SIZE)
	{
		count += tab[i];
		i ++;
	}
	return  count;
}

void	bench(int *tab, double disorder)
{
	int total;

	total = count_tab(tab);
	ft_printf("[bench] disorder:  %d%%\n", (int)(disorder * 100));
	ft_printf("[bench] strategy:  \n");
	ft_printf("[bench] total_ops:  %d\n", total);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n", tab[SA], tab[SB], tab[SS], tab[PA], tab[PB]);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:  %d\n", tab[RA], tab[RB], tab[RR], tab[RRA], tab[RRB],tab[RRR]);
}	