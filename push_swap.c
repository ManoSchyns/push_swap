/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:15:45 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 11:42:05 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// MAIN TEMPORAIRE

int main(int argc, char **argv)
{
    t_list      *stack_a;
    t_list      *stack_b;
    t_options   options;
	int n_op;

	(void)n_op;
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
    // bucket_sort(&stack_a, &stack_b);
    // radix_sort(&stack_a, &stack_b);
	// n2(&stack_a, &stack_b);
	if (options.strategy == STRAT_SIMPLE)
		n_op = n2(&stack_a, &stack_b);
	else if (options.strategy == STRAT_COMPLEX)
		radix_sort(&stack_a, &stack_b);
	else if (options.strategy == STRAT_MEDIUM)
		n_op = bucket_sort(&stack_a, &stack_b);
	else
		adaptive_sort(&stack_a, &stack_b);
    t_list *tmp = stack_a;
    while (tmp)
    {
        printf("\n%d a l index : %d\n", tmp->data, tmp->index);
        tmp = tmp->next;
    }
	//	printf("\n===operations : %d\n", n_op);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}