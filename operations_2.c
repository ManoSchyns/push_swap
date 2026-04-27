/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:32:16 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/27 17:03:21 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Shift up all elements of stack a by one.
The first element becomes the last one.
if flag == 1 
-> print ra\n
*/
void	ra(t_list	**lst, int flag)
{
	t_list	*first;
	t_list	*work;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = (*lst)->next;
	work = *lst;
	while (work->next != NULL)
		work = work->next;
	work->next = first;
	first->next = NULL;
	if (flag)
		write (1, "ra\n", 3);
}

/*
Shift up all elements of stack b by one.
The first element becomes the last one.
if flag == 1 
-> print rb\n
*/
void	rb(t_list	**lst, int flag)
{
	t_list	*first;
	t_list	*work;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = (*lst)->next;
	work = *lst;
	while (work->next != NULL)
		work = work->next;
	work->next = first;
	first->next = NULL;
	if (flag)
		write (1, "rb\n", 3);
}

/*
ra and rb at the same time.
-> print rr\n
*/
void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	write(1, "rr\n", 3);
}
