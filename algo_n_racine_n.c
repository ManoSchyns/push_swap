/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n_racine_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:52:52 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 08:24:10 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
calcul de la racinee caree d'un nombre
calcul en int -> approximatif
*/
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

static int get_max(t_list *lst)
{
    int i;
    int max_i;
    int max_data;

    if (lst == NULL)
        return (-1);
    i = 1;
    max_data = lst->data;
    max_i = 0;
    lst = lst->next;
    while (lst != NULL)
    {
        if(lst->data > max_data)
        {
            max_i = i;
            max_data = lst->data;
        }
        lst = lst->next;
        i ++;
    }
    return (max_i);
}

/*
envoie en fonction des indices calculées les elements de a par partie d'indice.
cela va déjà les pre trier dans lst_b
return le nombre d'operation effectuées dans le pointeur count
*/
void send_by_racine_buckets(t_list	**lst_a, t_list **lst_b, int *count)
{
	int i;
	int	j;
	int bucket_i_min;
	int bucket_i_max;
	int n_bucket;

	n_bucket = racine_carree(get_size(*lst_a));
	i = 0;
	bucket_i_min = 0;
	bucket_i_max = n_bucket;
	while (*lst_a != NULL)
	{
	
		if ((*lst_a)->index >= bucket_i_min && (*lst_a)->index < bucket_i_max)
		{
			pb(lst_a, lst_b);
			i ++;
		}
		else
			ra(lst_a, 1);
		*count += 1;
		if (i >= bucket_i_max)
		{
			bucket_i_min += n_bucket;
			bucket_i_max += n_bucket;
		}
	}
}

void send_back_a(t_list **lst_a, t_list **lst_b, int *count)
{
	int max_i;
	int len_b;

	len_b = get_size(*lst_b);
	while (*lst_b != NULL)
	{
		max_i = get_max(*lst_b);

		if(max_i < len_b / 2)
		{
			while (max_i > 0)
			{
				rb(lst_b, 1);
				*count += 1;
				max_i --;
			}
		}
		else
		{
			max_i = len_b - max_i;
			while (max_i > 0)
			{
				rrb(lst_b, 1);
				*count += 1;
				max_i --;
			}
		}
		pa(lst_a, lst_b);
		*count += 1;
		len_b --;
	}
}

/*
remonte les maximum dans b 1 a 1
Puis le push dans a
return le nombre d'operations
*/
int bucket_sort(t_list **lst_a, t_list **lst_b)
{
    int	*index_tab;
	int count;

	count = 0;
	index_tab = index_array(*lst_a);
	assign_index(*lst_a, index_tab);
	send_by_racine_buckets(lst_a, lst_b, &count);
	send_back_a(lst_a, lst_b, &count);
	return (count);
}

/*int main()
{
    
    printf("%d\n", b);
}*/