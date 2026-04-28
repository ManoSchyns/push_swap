/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 06:59:58 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/28 08:29:15 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n2(t_list **lst_a, t_list **lst_b)
{
	int is_sorted;
    int len;
    int i;
    int j;
    t_list  *work;

    len = get_size(*lst_a);
    i = 0;
    is_sorted = compute_disorder(*lst_a);
    while (i < len - 1 && is_sorted != 0)
    {
        j = 0;
        work = *lst_a;
        while (j < len - i - 1)
        {
            if (work->data > work->next->data)
                sa(work, 1);
            work = work->next;
            j ++;
        }
        is_sorted = compute_disorder(*lst_a);
        i ++;
    }
}

int main()
{
    
}