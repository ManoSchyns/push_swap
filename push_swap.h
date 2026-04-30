/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:07:25 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/28 08:07:50 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/ft_printf.h"

# define TAB_SIZE 11

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_options
{
	t_strategy	strategy;
	int			bench;
}	t_options;

typedef struct s_bucket
{
	int	start;
	int	end;
}	t_bucket;

// -- ops --
void	sa(t_list *lst_a, int flag, int *tab);
void	sb(t_list *lst_b, int flag, int *tab);
void	ss(t_list *lst_a, t_list *lst_b, int *tab);
void	pa(t_list **lst_a, t_list **lst_b, int *tab);
void	pb(t_list **lst_a, t_list **lst_b, int *tab);
void	ra(t_list	**lst, int flag, int *tab);
void	rb(t_list	**lst, int flag, int *tab);
void	rr(t_list **lst_a, t_list **lst_b, int *tab);
void	rra(t_list **lst, int flag, int *tab);
void	rrb(t_list **lst, int flag, int *tab);
void	rrr(t_list **lst_a, t_list **lst_b, int *tab);

// -- parsing --
int		is_valid_number(char *str);
int		string_to_int(char *str, int *out);
int		add_to_stack(t_list **stack, int value);
int		parse_args(int argc, char **argv, t_list **stack_a, t_options *options);

// -- utils -- 
int		ft_isdigit(int c);
int		is_in_stack(t_list *stack, int value);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_size(t_list *lst);
int		process_token(char *token, t_list **stack_a);
int		*index_array(t_list *stack);
int		get_max(t_list *lst);
char	**ft_split(char const *s, char c);
void	free_split(char **tab);
void	free_stack(t_list **stack);
void	assign_index(t_list *stack, int *indices);
void	bench(int *tab, double disorder, t_options options);
double	compute_disorder(t_list	*lst);

// -- sorting algorithms --
void	n2(t_list **lst_a, t_list **lst_b, int *tab);
void	bucket_sort(t_list **lst_a, t_list **lst_b, int *tab);
void	adaptive_sort(t_list **stack_a, t_list **stack_b, int *tab);
void	radix_sort(t_list **stack_a, t_list **stack_b, int *tab);

// -- pre-sort --
void	sort_three(t_list **lst_a, int *tab);
int		pre_sort(t_list **lst_a, int *tab);

#endif