/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 06:59:58 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 14:32:38 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
return -1 si lst est NULL
return l indicde du minimum dans la liste
*/
static int	get_min(t_list *lst)
{
	int	i;
	int	min_i;
	int	min_data;

	if (lst == NULL)
		return (-1);
	i = 1;
	min_data = lst->data;
	min_i = 0;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->data < min_data)
		{
			min_i = i;
			min_data = lst->data;
		}
		lst = lst->next;
		i ++;
	}
	return (min_i);
}

/*
	Recherche le minimum et l'ajoute en haut de la liste b
*/
static void	push_min_on_b(int *tab, t_list **lst_a, t_list **lst_b, int len)
{
	int	i;
	int	j;
	int	n_up;

	i = 0;
	while (i < len)
	{
		j = 0;
		n_up = get_min(*lst_a);
		while (j < n_up)
		{
			ra(lst_a, 1);
			tab[RA] += 1;
			j ++;
		}
		pb(lst_a, lst_b);
		tab[PB] += 1;
		i ++;
	}
}

/*
	tri de la liste chainee a par recherche du minimum	
	return : le nombre d operations effectees
*/
void	n2(t_list **lst_a, t_list **lst_b, int *tab)
{
	int	len;
	int	i;

	if (pre_sort(lst_a))
		return ;
	i = 0;
	len = get_size(*lst_a);
	push_min_on_b(tab, lst_a, lst_b, len);
	while (i < len)
	{
		pa(lst_a, lst_b);
		tab[PA] += 1;
		i ++;
	}
}
