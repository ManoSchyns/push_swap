/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:49:42 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/27 17:03:40 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Return : le dernier element de la liste
*/
static t_list	*get_last(t_list *lst)
{
	t_list	*prev;
	t_list	*work;

	prev = lst;
	work = lst->next;
	while (work->next != NULL)
	{
		work = work->next;
		prev = prev->next;
	}
	prev->next = NULL;
	return (work);
}

/*
	Décale tous les éléments de la pile a d'une position vers le bas.
	Le dernier élément devient le premier
	-> affiche rra\n si flag = 1
*/
void	rra(t_list **lst, int flag)
{
	t_list	*to_add;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	to_add = get_last(*lst);
	to_add->next = *lst;
	*lst = to_add;
	if (flag)
		write (1, "rra\n", 4);
}

/*
	Décale tous les éléments de la pile b d'une position vers le bas.
	Le dernier élément devient le premier.
	-> affiche rrb\n si flag = 1
*/
void	rrb(t_list **lst, int flag)
{
	t_list	*to_add;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	to_add = get_last(*lst);
	to_add->next = *lst;
	*lst = to_add;
	if (flag)
		write (1, "rrb\n", 4);
}

/*
	rra et rrb en même temps
	-> affiche rrr\n
*/
void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a, 0);
	rrb(lst_b, 0);
	write (1, "rrr\n", 4);
}
