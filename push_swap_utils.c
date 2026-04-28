/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:02:13 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/28 07:15:38 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
Return the number of elements in the list
*/
int	get_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i ++;
	}
	return (i);
}

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