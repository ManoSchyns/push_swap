/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 06:59:58 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/28 11:51:01 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
return -1 si lst est NULL
return l indicde du minimum dans la liste
*/
static int get_min(t_list *lst)
{
    int i;
    int min_i;
    int min_data;

    if (lst == NULL)
        return (-1);
    i = 1;
    min_data = lst->data;
    min_i = 0;
    lst = lst->next;
    while (lst != NULL)
    {
        if(lst->data < min_data)
        {
            min_i = i;
            min_data = lst->data;
        }
        lst =lst->next;
        i ++;
    }
    return (min_i);
}

/*
tri par recherche du minimum
return : le nombre d operations effectees
*/
int	n2(t_list **lst_a, t_list **lst_b)
{
    int n_up; 
    int len;
    int i;
    int j;
    int n_op;
	
    n_op = 0;
    i = 0;
    len = get_size(*lst_a);
    if (len == 1)
        return (0);
    if (len == 2)
    {
        if ((*lst_a)->data > (*lst_a)->next->data)
        {
            sa(*lst_a, 1);
            return (1);
        }
        return (0);
    }
    while (i < len)
    {
        j = 0;
        n_up = get_min(*lst_a);
        while (j < n_up)
        {
            ra(lst_a, 1);
            j ++;
        }
        n_op += j + 1;
        pb(lst_a, lst_b);
        i ++;
    }
    i = 0;
    while (i < len)
    {
        pa(lst_a, lst_b);
        n_op ++;
        i ++;
    }
    printf("===> pour taille : %d, nombre d operations : %d", len, n_op);
    return (n_op);
}