/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n_racine_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:52:52 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/28 16:44:22 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int racine_carree(int len)
{
    int i;

    if (len == 0)
        return (0);
    i = 1;
    while (i * i <= len)
    {
        if (i * i == len)
            return (i);
        i ++;
    }
    return (i);
}

void define_index(t_list *lst, int len)
{
    int n_buckets;
    int i;
    t_list *work;

    i = 0;
    n_buckets = racine_carree(len);
    work = lst;
    while (lst != NULL)
    {
        lst->index = i / n_buckets;
        lst = lst->next;
        i ++;
    }
}

/*
mets tout les elements de a dans b
return le nombre d operations
*/
int full_b(t_list **lst_a, t_list **lst_b)
{
    int i;

    i = 0;
    while (*lst_a)
    {
        pb(lst_a, lst_b);
        i ++;
    }
    return (i);
}

void bucket_sort(t_list **lst_a, t_list **lst_b)
{
    int len;
    int count;

    len = get_size(*lst_a);
    count = define_index(*lst_a, len);
    
}

/*int main()
{
    
    printf("%d\n", b);
}*/