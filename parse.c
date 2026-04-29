/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-gall <dle-gall@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 22:06:25 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/27 22:06:25 by dle-gall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Verif que la string représente un entier valide
	return 1 si valide, 0 sinon
*/
int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
	Convertit une string en int	+ gere le INT_MAX et INT_MIN
*/
int string_to_int(char *str, int *out)
{
	int i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}
/*
	Cherche si 'value' est déjà présent dans la stack
	return 1 si oui, 0 si non
*/
int is_in_stack(t_list *stack, int value)
{
	 t_list *p;

	p = stack;
	while(p)
	{
		if (p->data == value)
			return (1);
		else
			p = p->next;
	}
	return (0);
}

/*
	créer un nouveau noeud t_list avec 'value' et l'ajoute a la fin de stack
	return 1 si succes, 0 si malloc fail
*/
int add_to_stack(t_list **stack, int value)
{
	t_list *new_node;
	t_list *work;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return (1);
	}
	work = *stack;
	while (work->next != NULL)
		work = work->next;
	work->next = new_node;
	return (1);
}

/*
	boucle principale du parsing, pour chaque argv[i], valide et ajoute a la stack
	return 1 si tout est ok, 0 si erreur
*/
int parse_args(int argc, char **argv, t_list **stack_a, t_options *options)
{
	int i;
	int j;
	char **tokens;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if(ft_strncmp(argv[i], "--simple", 8) == 0)
				options->strategy = STRAT_SIMPLE;
			else if(ft_strncmp(argv[i], "--medium", 8) == 0)
				options->strategy = STRAT_MEDIUM;
			else if(ft_strncmp(argv[i], "--complex", 9) == 0)
				options->strategy = STRAT_COMPLEX;
			else if(ft_strncmp(argv[i], "--adaptive", 10) == 0)
				options->strategy = STRAT_ADAPTIVE;
			else if(ft_strncmp(argv[i], "--bench", 7) == 0)
				options->bench = 1;
			else
			{
				write(2, "FlagsError\n", 11); // A MODIFIER AVANT DE RENDRE
				return (0);
			}
			i++;
			continue;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			if (!process_token(tokens[j], stack_a))
			{
				free_split(tokens);
				return (0);
			}
			j++;
		}
		free_split(tokens);
		i++;
	}
	return (1);
}

// MAIN TEMPORAIRE

int main(int argc, char **argv)
{
    t_list      *stack_a;
    t_list      *stack_b;
    t_options   options;
	int n_op;

    stack_a = NULL;
    stack_b = NULL;
    options.strategy = STRAT_ADAPTIVE;
    options.bench = 0;
    if (argc < 2)
        return (0);
    if (!parse_args(argc, argv, &stack_a, &options))
    {
        write(2, "Error\n", 6);
        free_stack(&stack_a);
        return (1);
    }    
    // bucket_sort(&stack_a, &stack_b);
    // radix_sort(&stack_a, &stack_b);
	// n2(&stack_a, &stack_b);
	if (options.strategy == STRAT_SIMPLE)
		n_op = n2(&stack_a, &stack_b);
	else if (options.strategy == STRAT_COMPLEX)
		radix_sort(&stack_a, &stack_b);
	else if (options.strategy == STRAT_MEDIUM)
		n_op = bucket_sort(&stack_a, &stack_b);
	else
		adaptive_sort(&stack_a, &stack_b);
    t_list *tmp = stack_a;
    while (tmp)
    {
        printf("\n%d a l index : %d\n", tmp->data, tmp->index);
        tmp = tmp->next;
    }
		printf("\n===operations : %d\n", n_op);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}