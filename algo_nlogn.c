/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_nlogn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 08:46:39 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/29 09:24:22 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Compte combien il y a de nombre plus petit que temp->data et le met dans indices[i]
*/
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

/*
    Calcule combien de chiffres BINAIRES regarder pour triers les nombres
*/
int get_max_bits(int size)
{
    int bits;

    bits = 0;
    size--; // car sinon il y a (size * 2) valeurs, donc c'est trop : Exemple juste en dessous de la fonction (aussi car les indices vont de 0 a (size-1) et non a size)
    while (size > 0)
    {
        bits++; // bits + 1 a chaque tour pour compter combien il faut de chiffre en binaire pour trier la totalité des nombres
        size >>= 1; // 1010 1010 -> 0101 0101 (autrement dit : Divise par deux)
    }
    return (bits);
}

/*
    pour 8 value : 
        sans size--;
            Tour 1 : size = 8 (1000 en binaires) -> bits = 1
            Tour 2 : size = 4 (0100 en binaires) -> bits = 2
            Tour 3 : size = 2 (0010 en binaires) -> bits = 3
            Tour 4 : size = 1 (0001 en binaires) -> bits = 4
            Tour 5 : size = 0 (0000 en binaires) -> STOP
            nombre total de valeur possible avec 4 bits = 16 
        avec size--;
            Tour 1 : size = 7 (0111 en binaires) -> bits = 1
            Tour 2 : size = 3 (0011 en binaires) -> bits = 2
            Tour 3 : size = 1 (0001 en binaires) -> bits = 3
            Tour 4 : size = 0 (0000 en binaires) -> STOP
            nombre total de valeur possible avec 3 bits = 8  
*/

/*
    prend l'array *indices (créer dans index_array()) et ajoute chaque nombre dans la stack
*/
void assign_index(t_list *stack, int *indices)
{
    int i;
    t_list *work;
    
    if (stack == NULL || indices == NULL)
        return ;
    i = 0;
    work = stack; // work pointe sur le premier element de la stack
    while (work != NULL) // on tourne tout le temps qu'il y a des elements
    {
        work->index = indices[i]; // on met la valeur d'indices[i] dans work->index
        i++;
        work = work->next;
    }
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int *indices;
    int size;
    int max_bits;
    int i;
    int bit;
    int current_index;
    int bit_value;
    int count;

    count = 0;
    size = get_size(*stack_a);  // on obtiens le nombre d'elements
    indices = index_array(*stack_a); // créer les indices
    if (!indices)
        return ;
    assign_index(*stack_a, indices); // attribué les indices 
    max_bits = get_max_bits(size);  // savoir combien de bits regarder
    bit = 0;
    while (bit < max_bits) 
    {
        i = 0;
        while (i < size)
        {
            
            current_index = (*stack_a)->index; // recuperer l'index du PREMIER element de stack_a

            // on extrait le bit 
            bit_value = (current_index >> bit) & 1; // on vérifie si le bit courant est 0 ou 1

            if (bit_value == 0)
                pb(stack_a, stack_b); // si c'est 0 on envoie dans stack_b
            else
                ra(stack_a, 1); // si c'est 1 on rotate dans stack_a
            count ++;
            i++;
        }
        // on remet tout les elements de stack_b dans stack_a
        while (*stack_b != NULL)
        {
            pa(stack_a, stack_b);
            count ++;
        }
        bit++; // on passe au bit suivant
    }
    //printf("\n==count: %d\n", count);
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
