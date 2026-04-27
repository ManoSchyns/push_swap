/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschyns <mano.schyns@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:07:25 by mschyns           #+#    #+#             */
/*   Updated: 2026/04/27 17:05:42 by mschyns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

// -- ops --
void	sa(t_list *lst_a, int flag);
void	sb(t_list *lst_b, int flag);
void	ss(t_list *lst_a, t_list *lst_b);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list	**lst, int flag);
void	rb(t_list	**lst, int flag);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst, int flag);
void	rrb(t_list **lst, int flag);
void	rrr(t_list **lst_a, t_list **lst_b);

// -- parsing --
int		is_valid_number(char *str);
int		string_to_int(char *str, int *out);
int		add_to_stack(t_list **stack, int value);
int		parse_args(int argc, char **argv, t_list **stack_a);

// -- utils -- 
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int     process_token(char *token, t_list **stack_a);
void    free_split(char **tab);
void    free_stack(t_list **stack);
int		is_in_stack(t_list *stack, int value);

#endif