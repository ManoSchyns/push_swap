/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_nlogn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 08:46:39 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/28 15:22:01 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *index_array(t_list *stack)
{
    int size;
    int *indices;
    int i;
    t_list *work;
    int count;
    t_list *temp;

    size = get_size(stack);
    indices = malloc(sizeof(int) * size);
    if (!indices)
        return (NULL);
    i = 0;
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

int get_max_bits(int size)
{
    int bits;

    bits = 0;
    size--;
    while (size > 0)
    {
        bits++;
        size >>= 1;
    }
    return (bits);
}

void assign_index(t_list *stack, int *indices)
{
    int i;
    t_list *work;
    
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

void radix_sort(t_list **stack_a, t_list **stack_b, t_options *options)
{
    (void)options;
    
    int *indices;
    int size;
    int max_bits;
    int i;
    int bit;
    int current_index;
    int bit_value;
    int count;

    count = 0;
    size = get_size(*stack_a);
    indices = index_array(*stack_a);
    if (!indices)
        return ;
    assign_index(*stack_a, indices);
    max_bits = get_max_bits(size);
    bit = 0;
    while (bit < max_bits)
    {
        i = 0;
        while (i < size)
        {
            /*recuperer l'index du premier element*/
            current_index = (*stack_a)->index;

            /* on extrait le bit */
            bit_value = (current_index >> bit) & 1;

            if (bit_value == 0)
                pb(stack_a, stack_b);
            else
                ra(stack_a, 1);
            count ++;
            i++;
        }
        while (*stack_b != NULL)
        {
            pa(stack_a, stack_b);
            count ++;
        }
        bit++;
    }
    printf("\n==count: %d\n", count);
}
