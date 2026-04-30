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
	Cherche si 'value' est déjà présent dans la stack
	return 1 si oui, 0 si non
*/
int	is_in_stack(t_list *stack, int value)
{
	t_list	*p;

	p = stack;
	while (p)
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
int	add_to_stack(t_list **stack, int value)
{
	t_list	*new_node;
	t_list	*work;

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
	Enregistre les options enregistées par l'utilisateur.
	Enregistre, comment le programme devra etre lancé
	Si erreur -> return 0
	si non 1
*/
static	int	set_options(char *arg, t_options *options)
{
	static int	flag;

	if (!flag && ft_strncmp(arg, "--simple", 8) == 0)
		options->strategy = STRAT_SIMPLE;
	else if (!flag && ft_strncmp(arg, "--medium", 8) == 0)
		options->strategy = STRAT_MEDIUM;
	else if (!flag && ft_strncmp(arg, "--complex", 9) == 0)
		options->strategy = STRAT_COMPLEX;
	else if (!flag && ft_strncmp(arg, "--adaptive", 10) == 0)
		options->strategy = STRAT_ADAPTIVE;
	else if (options->bench == 0 && ft_strncmp(arg, "--bench", 7) == 0)
		options->bench = 1;
	else
		return (0);
	if (options->bench == 0)
		flag = 1;
	return (1);
}

/*
	Verifie si les nombre rentrées sont valide
	Return 1 si valide
	Return 0 si non
*/
static int	parse_tokens(char **tokens, t_list **stack_a)
{
	int	j;

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
	return (1);
}

/*
	boucle principale du parsing, pour chaque argv[i], 
	valide et ajoute a la stack
	return 1 si tout est ok, 0 si erreur
*/
int	parse_args(int argc, char **argv, t_list **stack_a, t_options *options)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (set_options(argv[i], options) == 0)
				return (0);
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		if (parse_tokens(tokens, stack_a) == 0)
			return (0);
		free_split(tokens);
		i++;
	}
	return (1);
}
