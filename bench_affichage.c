/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_affichage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:58:14 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 15:52:27 by mschyns          ###   ########.fr       */
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

void	print_stategi_char(t_options options, double disorder)
{
	char *str_adap;
	char *str_nlogn;
	char *str_n_racine_n;
	char *str_n2;

	str_adap = "Adaptive / ";
	str_n2 = "O(n²)";
	str_n_racine_n = "O(n√n)";
	str_nlogn = "O(n log n)";
	if (options.strategy == STRAT_ADAPTIVE)
	{
		ft_printf("[bench] strategy:  %s", str_adap);
		if (disorder < 0.2)
        	ft_printf("%s\n", str_n2);
   		 else if (disorder < 0.5)
        	ft_printf("%s\n", str_n_racine_n);
    	else
        	ft_printf("%s\n", str_nlogn);
	}
	else if (options.strategy == STRAT_SIMPLE)
		ft_printf("[bench] strategy:  %s\n", str_n2);
	else if (options.strategy == STRAT_MEDIUM)
		ft_printf("[bench] strategy:  %s\n", str_n_racine_n);
	else if (options.strategy == STRAT_COMPLEX)
		ft_printf("[bench] strategy:  %s\n", str_nlogn);
}

void	bench(int *tab, double disorder, t_options options)
{
	int total;
	int nb;
	int digit_1;
	int digit_2;

	nb = (int)(disorder * 100);
	digit_1 = (int)(disorder * 1000) % 10;
	digit_2 = (int)(disorder * 10000) % 10;
	total = count_tab(tab);
	ft_printf("[bench] disorder:  %d.%d%d%%\n", nb, digit_1, digit_2);
	print_stategi_char(options, disorder);
	ft_printf("[bench] total_ops:  %d\n", total);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n", tab[SA], tab[SB], tab[SS], tab[PA], tab[PB]);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:  %d\n", tab[RA], tab[RB], tab[RR], tab[RRA], tab[RRB],tab[RRR]);
}	