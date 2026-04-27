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

# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

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

#endif