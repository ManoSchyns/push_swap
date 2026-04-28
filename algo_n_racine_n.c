/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n_racine_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:52:52 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/28 13:58:16 by mschyns          ###   ########.fr       */
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
    return (i - 1);
}

int main()
{
    printf("%d\n", racine_carree(5));
}