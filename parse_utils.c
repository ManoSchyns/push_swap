/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-gall <dle-gall@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:06:01 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/27 23:06:01 by dle-gall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Verifie la validité des token. Des nombre
	Et essaie de les ajouter dans la stack
*/
int	process_token(char *token, t_list **stack_a)
{
	int	value;

	if (!is_valid_number(token))
		return (0);
	if (!string_to_int(token, &value))
		return (0);
	if (is_in_stack(*stack_a, value))
		return (0);
	if (!add_to_stack(stack_a, value))
		return (0);
	return (1);
}

/*
	Verif que la string représente un entier valide
	return 1 si valide, 0 sinon
*/
int	is_valid_number(char *str)
{
	int	i;

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
int	string_to_int(char *str, int *out)
{
	int		i;
	int		sign;
	long	result;

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
	Libere la mémoire d'un tableau de chaine de caractère
*/
void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
	Libere la memoire d'une liste chainee
*/
void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
