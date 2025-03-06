/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:43:31 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 17:35:36 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two_three(t_list **s_a)
{
	if (ft_lstsize(*s_a) == 2)
		sort_two(s_a);
	else
		sort_three(s_a);
	store_instructions(NULL, 1);
}

void	sort_two(t_list **s_a)
{
	if (get_number_node(*s_a) > get_number_node((*s_a)->next))
		s_stack(s_a);
}

void	sort_three(t_list **s_a)
{
	while (is_sorted(*s_a) == 0)
	{
		if (get_number_node(*s_a) > get_number_node((*s_a)->next))
			s_stack(s_a);
		if (get_number_node((*s_a)->next) >
			get_number_node((*s_a)->next->next))
			rr_stack(s_a);
	}
}

void	move_to_top(t_list **stack, t_list *target)
{
	int	size;
	
	size = ft_lstsize(*stack) / 2;
	if (get_index(target) < size)
		while (get_presort_num(*stack) != get_presort_num(target))
			r_stack(stack);
	else
		while (get_presort_num(*stack) != get_presort_num(target))
			rr_stack(stack);
}

t_list	*get_small_node(t_list *stack)
{
	t_list *node;

	node = stack;
	while (stack)
	{
		if (get_presort_num(node) > get_presort_num(stack))
			node = stack;
		stack = stack->next;
	}
	return (node);
}

void	sort_five(t_list **sa, t_list **sb)
{
	t_list	*node;

	node = NULL;
	while (ft_lstsize(*sa) > 3)
	{
		node = get_small_node(*sa);
		move_to_top(sa, node);
		p_stack(sb, sa);
		reindex_stack(sa, sb);
	}
	sort_three(sa);
	p_stack(sa, sb);
	p_stack(sa, sb);
	store_instructions(NULL, 1);	
}