/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_nlogn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 08:46:39 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/29 14:54:00 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*index_array(t_list *stack)
{
	int		*indices;
	t_list	*work;
	int		count;
	t_list	*temp;

	int (i) = 0;
	indices = malloc(sizeof(int) * get_size(stack));
	if (!indices)
		return (NULL);
	work = stack;
	while (work != NULL)
	{
		count = 0;
		temp = stack;
		while (temp != NULL)
		{
			if (temp->data < work->data)
				count++;
			temp = temp->next;
		}
		indices[i] = count;
		i++;
		work = work->next;
	}
	return (indices);
}

int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	size--;
	while (size > 0)
	{
		bits++;
		size >>= 1;
	}
	return (bits);
}

void	assign_index(t_list *stack, int *indices)
{
	int		i;
	t_list	*work;

	if (stack == NULL || indices == NULL)
		return ;
	i = 0;
	work = stack;
	while (work != NULL)
	{
		work->index = indices[i];
		i++;
		work = work->next;
	}
}

static void	process_bit(t_list **stack_a, t_list **stack_b, int bit, int size)
{
	int	i;
	int	bit_value;

	i = 0;
	while (i < size)
	{
		bit_value = ((*stack_a)->index >> bit) & 1;
		if (bit_value == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		i++;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	*indices;
	int	size;
	int	max_bits;
	int	bits;

	size = get_size(*stack_a);
	indices = index_array(*stack_a);
	if (!indices)
		return ;
	assign_index(*stack_a, indices);
	free(indices);
	max_bits = get_max_bits(size);
	bits = 0;
	while (bits < max_bits)
	{
		process_bit(stack_a, stack_b, bits, size);
		bits++;
	}
}

/*
	EXEMPLE RADIX SORT :

	Nombres : [3, 1, 2]
	Indices : [2, 0, 1]  rangée du plus petit au plus grand
	(nb 3 = idx 2 = 3eme, nb 1 = idx 0 = 1er, nb 2 = idx 1 = 2eme petit nombre)

	En binaire : [3](2=10), [1](0=00), [2](1=01)
	Max bits = 2
	--------------
	TOUR DE BOUCLE POUR BIT 0 (on regarde le dernier bit)

	Start  : A: [3](2=0) [1](0=0) [2](1=1) | B: []

	[3](2) bit 0 = 0 -> pb    : A: [1](0) [2](1) | B: [3](2)
	[1](0) bit 0 = 0 -> pb    : A: [2](1) | B: [1](0) [3](2)
	[2](1) bit 0 = 1 -> ra    : A: [2](1) | B: [1](0) [3](2)

	Remettre B dans A : A: [3](2) [1](0) [2](1) | B: []

	TOUR DE BOUCLE POUR BIT 1 (regarder le l'avant dernier bit)

	Start  : A: [3](2=1) [1](0=0) [2](1=0) | B: []

	[3](2) bit 1 = 1 -> ra    : A: [1](0) [2](1) [3](2) | B: []
	[1](0) bit 1 = 0 -> pb    : A: [2](1) [3](2) | B: [1](0)
	[2](1) bit 1 = 0 -> pb    : A: [3](2) | B: [2](1) [1](0)

	Remettre B dans A : A: [1](0) [2](1) [3](2) | B: []

	Résultat : Indices triés [0, 1, 2] = Nombres triés [1, 2, 3]
*/