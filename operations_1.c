/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:05:59 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/27 16:32:07 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements
If flag == 1 -> print sa\n
*/
void	sa(t_list *lst_a, int flag)
{
	int	temp;

	if (lst_a == NULL)
		return ;
	if (lst_a->next == NULL)
		return ;
	temp = lst_a->data;
	lst_a->data = lst_a->next->data;
	lst_a->next->data = temp;
	if (flag)
		write (1, "sa\n", 3);
}

/*
Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements
If flag == 1 -> print sb\n
*/
void	sb(t_list *lst_b, int flag)
{
	int	temp;

	if (lst_b == NULL)
		return ;
	if (lst_b->next == NULL)
		return ;
	temp = lst_b->data;
	lst_b->data = lst_b->next->data;
	lst_b->next->data = temp;
	if (flag)
		write (1, "sb\n", 3);
}

/*
Swap the first two elements at the top of stack a and b.
-> Print ss\n
*/
void	ss(t_list *lst_a, t_list *lst_b)
{
	sa(lst_a, 0);
	sb(lst_b, 0);
	write (1, "ss\n", 3);
}

/*
Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
-> Print pa\n
*/
void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*to_add;

	if (*lst_b == NULL)
		return ;
	to_add = *lst_b;
	*lst_b = (*lst_b)->next;
	to_add->next = *lst_a;
	*lst_a = to_add;
	write(1, "pa\n", 3);
}

/*
Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
-> print pb\n
*/
void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*to_add;

	if (*lst_a == NULL)
		return ;
	to_add = *lst_a;
	*lst_a = (*lst_a)->next;
	to_add->next = *lst_b;
	*lst_b = to_add;
	write(1, "pb\n", 3);
}
