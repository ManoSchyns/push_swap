/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:03:01 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/30 09:08:01 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_value(t_list **lst_a, int *top, int *mid, int *bot)
{
	*top = (*lst_a)->data;
	*mid = (*lst_a)->next->data;
	*bot = (*lst_a)->next->next->data;
}

/*
	trie une stack de 3 elements en 2 ops max
*/
void	sort_three(t_list **lst_a, int *tab)
{
	int	top;
	int	mid;
	int	bot;

	assign_value(lst_a, &top, &mid, &bot);
	if (top > mid && mid < bot && top < bot)
		sa(*lst_a, 1, tab);
	else if (top > mid && mid > bot)
	{
		sa(*lst_a, 1, tab);
		rra(lst_a, 1, tab);
	}
	else if (top > mid && mid < bot && top > bot)
	{
		ra(lst_a, 1, tab);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		sa(*lst_a, 1, tab);
		ra(lst_a, 1, tab);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(lst_a, 1, tab);
}

/*
	gère les petits cas
*/
int	pre_sort(t_list **lst_a, int *tab)
{
	int	size;

	if (compute_disorder(*lst_a) == 0.00)
		return (1);
	size = get_size(*lst_a);
	if (size == 2)
	{
		sa(*lst_a, 1, tab);
		return (1);
	}
	if (size == 3)
	{
		sort_three(lst_a, tab);
		return (1);
	}
	return (0);
}
