/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-gall <dle-gall@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:06:01 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/27 23:06:01 by dle-gall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int process_token(char *token, t_list **stack_a)
{
	int value;

	if (!is_valid_number(token))
		return (0);
	if (!string_to_int(token, &value))
		return (0);
	if (is_in_stack(*stack_a, value))
		return (0);
	if (!add_to_stack(stack_a, value))
		return (0);
	return (1);
}

void free_split(char **tab)
{
    int i;

    if (!tab)
        return ;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void free_stack(t_list **stack)
{
    t_list  *current;
    t_list  *next;

    if (stack == NULL || *stack == NULL)
        return ;
    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

void adaptive_sort(t_list **stack_a, t_list **stack_b)
{
    double disorder;

    disorder = compute_disorder(*stack_a);
    if (disorder < 0.2)
        n2(stack_a, stack_b);
    else if (disorder < 0.5)
        bucket_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}