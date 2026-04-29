/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptatif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:14:00 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:59:13 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Return : 0 if the list is sorted.
Return : 1 if the list is in the worst order possible
Return : a number between 0 and 1 wich tell how good is the liste sorted
If the number is close to 0 -> we are almost sorted.
If the number is close to 1 -> we are quite far.
*/
double	compute_disorder(t_list	*lst)
{
	double	mistakes;
	double	total_pairs;
	t_list	*work;
	t_list	*next;

	mistakes = 0.0;
	total_pairs = 0.0;
	work = lst;
	while (work != NULL)
	{
		next = work->next;
		while (next != NULL)
		{
			total_pairs += 1;
			if (work->data > next->data)
				mistakes += 1;
			next = next->next;
		}
		work = work->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

/*// TODO : Pour les petits cas ??
static int	handle_little_case(int len, t_list **lst_a)
{
	if (len == 1)
		return (0);
	if (len == 2)
	{
		if ((*lst_a)->data > (*lst_a)->next->data)
		{
			sa(*lst_a, 1);
			return (1);
		}
	}
	return (0);
}*/

void adaptive_sort(t_list **stack_a, t_list **stack_b, int *tab)
{
    double disorder;

    disorder = compute_disorder(*stack_a);
    if (disorder < 0.2)
        n2(stack_a, stack_b, tab);
    else if (disorder < 0.5)
        bucket_sort(stack_a, stack_b, tab);
    else
        radix_sort(stack_a, stack_b, tab);
}