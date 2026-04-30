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
	Échange les deux premiers éléments en haut de la pile a.
	Ne fait rien s'il n'y a qu'un seul élément ou aucun.
	Si flag == 1 -> affiche sa\n
*/
void	sa(t_list *lst_a, int flag, int *tab)
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
	{
		write (1, "sa\n", 3);
		tab[SA] += 1;
	}
}

/*
	Échange les deux premiers éléments en haut de la pile b.
	Ne fait rien s'il n'y a qu'un seul élément ou s'il n'y en a aucun.
	Si flag == 1 -> affiche sb\n
*/
void	sb(t_list *lst_b, int flag, int *tab)
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
	{
		write (1, "sb\n", 3);
		tab[SB] += 1;
	}
}

/*
	Échange les deux premiers éléments en haut de la pile a et b.
	-> Affiche ss\n
*/
void	ss(t_list *lst_a, t_list *lst_b, int *tab)
{
	sa(lst_a, 0, tab);
	sb(lst_b, 0, tab);
	write (1, "ss\n", 3);
	tab[SS] += 1;
}

/*
	Prend le premier élément en haut de b et le place en haut de a.
	Ne fait rien si b est vide.
	-> Affiche pa\n
*/
void	pa(t_list **lst_a, t_list **lst_b, int *tab)
{
	t_list	*to_add;

	if (*lst_b == NULL)
		return ;
	to_add = *lst_b;
	*lst_b = (*lst_b)->next;
	to_add->next = *lst_a;
	*lst_a = to_add;
	write(1, "pa\n", 3);
	tab[PA] += 1;
}

/*
	Prend le premier élément en haut de a et le place en haut de b.
	Ne fait rien si a est vide.
	-> print pb\n
*/
void	pb(t_list **lst_a, t_list **lst_b, int *tab)
{
	t_list	*to_add;

	if (*lst_a == NULL)
		return ;
	to_add = *lst_a;
	*lst_a = (*lst_a)->next;
	to_add->next = *lst_b;
	*lst_b = to_add;
	write(1, "pb\n", 3);
	tab[PB] += 1;
}
