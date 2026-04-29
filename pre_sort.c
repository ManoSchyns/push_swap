/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-gall <dle-gall@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:03:01 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/29 20:03:01 by dle-gall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Return 1 si la liste est trié en ordre croissant
	Return 0 sinon
*/
int	is_sorted(t_list *lst)
{
	if (lst == NULL)
		return (1);
	while (lst->next != NULL)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/*
	trie une stack de 3 elements en 2 ops max
*/
void	sort_three(t_list **lst_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*lst_a)->data;
	mid = (*lst_a)->next->data;
	bot = (*lst_a)->next->next->data;
	if (top > mid && mid < bot && top < bot)
		sa(*lst_a, 1);
	else if (top > mid && mid > bot)
	{
		sa(*lst_a, 1);
		rra(lst_a, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(lst_a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(*lst_a, 1);
		ra(lst_a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(lst_a, 1);
}

/*
	gère les petits cas
*/
int	pre_sort(t_list **lst_a)
{
	int	size;

	if (is_sorted(*lst_a))
		return (1);
	size = get_size(*lst_a);
	if (size == 2)
	{
		sa(*lst_a, 1);
		return (1);
	}
	if (size == 3)
	{
		sort_three(lst_a);
		return (1);
	}
	return (0);
}
