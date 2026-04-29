/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:15:45 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 15:54:28 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Rempli le tableau de 0
*/
void	full_0(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}

void	apply_stategie(t_options options, t_list **stack_a, t_list **stack_b,
		int *tab)
{
	if (options.strategy == STRAT_SIMPLE)
		return (n2(stack_a, stack_b, tab));
	else if (options.strategy == STRAT_COMPLEX)
		return (radix_sort(stack_a, stack_b, tab));
	else if (options.strategy == STRAT_MEDIUM)
		return (bucket_sort(stack_a, stack_b, tab));
	else
		return (adaptive_sort(stack_a, stack_b, tab));
}

// MAIN TEMPORAI
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_options	options;
	int			tab[TAB_SIZE];
	double		disorder;
	t_list		*tmp;

	full_0(tab, TAB_SIZE);
	stack_a = NULL;
	stack_b = NULL;
	options.strategy = STRAT_ADAPTIVE;
	options.bench = 0;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a, &options))
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		return (1);
	}
	disorder = compute_disorder(stack_a);
	apply_stategie(options, &stack_a, &stack_b, tab);
	if (options.bench == 1)
		bench(tab, disorder, options);
	tmp = stack_a;
	while (tmp)
	{
		printf("\n%d a l index : %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
