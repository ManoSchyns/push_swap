/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:02:13 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/29 11:17:52 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Compare 2 chaine de caracteres. 
	Return un positif si s1 > s2
	Return un negatif si s2 > s1
	return 0 si egales
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}

/*
	Retourne 1 si le caractere est un chiffre.
	0 si non
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
	Return the number of elements in the list
*/
int	get_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i ++;
	}
	return (i);
}

/*
	Retourne l'indice de la valeur maximale de la liste
*/
int	get_max(t_list *lst)
{
	int	i;
	int	max_i;
	int	max_data;

	if (lst == NULL)
		return (-1);
	i = 1;
	max_data = lst->data;
	max_i = 0;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->data > max_data)
		{
			max_i = i;
			max_data = lst->data;
		}
		lst = lst->next;
		i ++;
	}
	return (max_i);
}
