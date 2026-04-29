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
	Décale tous les éléments de la pile a d'une position vers le haut.
	Le premier élément devient le dernier.
	Si flag == 1
	-> afficher ra\n
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
	Décale tous les éléments de la pile b d'une position vers le haut.
	Le premier élément devient le dernier.
	Si flag == 1
	-> affiche rb\n
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
	ra and rb en même temps.
	-> affiche rr\n
*/
void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	write(1, "rr\n", 3);
}
