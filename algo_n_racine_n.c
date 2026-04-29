/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n_racine_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:52:52 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 15:14:58 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	calcul de la racinee caree d'un nombre
	calcul en int -> approximatif
*/
static int	racine_carree(int len)
{
	int	i;

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

/*
	envoie en fonction des indices calculées les elements de a groupes d'indices
	cela va déjà les pre trier dans lst_b
	return le nombre d'operation effectuées dans le pointeur count
*/
void	send_by_racine_buckets(t_list	**lst_a, t_list **lst_b, int *tab)
{
	int			i;
	t_bucket	bucket;

	i = 0;
	bucket.start = 0;
	bucket.end = racine_carree(get_size(*lst_a));
	while (*lst_a != NULL)
	{
		if ((*lst_a)->index >= bucket.start && (*lst_a)->index < bucket.end)
		{
			pb(lst_a, lst_b);
			tab[PB] += 1;
			i ++;
		}
		else
		{
			tab[RA] += 1;
			ra(lst_a, 1);
		}
		if (i >= bucket.end)
		{
			bucket.start = bucket.end;
			bucket.end += racine_carree(get_size(*lst_a));
		}
	}
}

/*
	Remonte au sommet de la liste b la valeur maximale presente dans celle-ci
*/
void	move_max_up_on_b(int max_i, int len_b, t_list **lst_b, int *tab)
{
	if (max_i < len_b / 2)
	{
		while (max_i > 0)
		{
			rb(lst_b, 1);
			tab[RB] += 1;
			max_i --;
		}
	}
	else
	{
		max_i = len_b - max_i;
		while (*lst_b != NULL && (*lst_b)->next != NULL && max_i > 0)
		{
			tab[RRB] += 1;
			rrb(lst_b, 1);
			max_i --;
		}
	}
}

/*
	Renvoie les max 1 a 1 de la liste b à la liste a
*/
void	send_back_a(t_list **lst_a, t_list **lst_b, int *tab)
{
	int	max_i;
	int	len_b;

	len_b = get_size(*lst_b);
	while (*lst_b != NULL)
	{
		max_i = get_max(*lst_b);
		move_max_up_on_b(max_i, len_b, lst_b, tab);
		pa(lst_a, lst_b);
		tab[PA] += 1;
		len_b --;
	}
}

/*
	Bucket sort
	-> Tri une liste chainee en la divisant en
	Racine caree de la taille de la chaine sous liste.
	Ces sous listes ne sont pas crées mais representée par des index

	Le tri s'effectue en envoyant dans b, par chunk les elements de a
	Puis en recupérant de maniere efficace le maximum dans b 
	et en le renvoyant dans a
*/
void	bucket_sort(t_list **lst_a, t_list **lst_b, int *tab)
{
	int	*index_tab;

	index_tab = index_array(*lst_a);
	assign_index(*lst_a, index_tab);
	send_by_racine_buckets(lst_a, lst_b, tab);
	send_back_a(lst_a, lst_b, tab);
}

/*int main()
{
	
	printf("%d\n", b);
}*/