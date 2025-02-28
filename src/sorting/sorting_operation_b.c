/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:28:29 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 15:31:42 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rb_pa_top(t_list **s_a, t_list **s_b, t_list *node, int partition)
{
	int	i;
	int	index;

	index = get_index(node);
	i = -1;
	while (++i < index)
		r_stack(&*s_b);
	p_stack(s_a, s_b);
	change_location(s_a, TOP_A);
	change_par(s_a, partition);
}

void	rrb_pa_top(t_list **s_a, t_list **s_b, t_list *node, int partition)
{
	int	i;
	int	index;

	index = get_index(node);
	i = ft_lstsize(*s_b) + 1;
	while (--i > index)
		rr_stack(s_b);
	p_stack(s_a, s_b);
	change_location(s_a, TOP_A);
	change_par(s_a, partition);
}

void	rb_pa_bot(t_list **s_a, t_list **s_b, t_list *node, int partition)
{
	int	i;
	int	index;

	index = get_index(node);
	i = -1;
	while (++i < index)
		r_stack(s_b);
	p_stack(s_a, s_b);
	change_location(s_a, BOT_A);
	change_par(s_a, partition);
	r_stack(s_a);
}

void	rrb_pa_bot(t_list **s_a, t_list **s_b, t_list *node, int partition)
{
	int	i;
	int	index;

	index = get_index(node);
	i = ft_lstsize(*s_b) + 1;
	while (--i > index)
		rr_stack(s_b);
	p_stack(s_a, s_b);
	change_location(s_a, BOT_A);
	change_par(s_a, partition);
	r_stack(s_a);
}
