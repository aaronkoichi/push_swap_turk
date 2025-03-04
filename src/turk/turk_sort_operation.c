/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:29:32 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 19:35:30 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Determine where to insert the node to stack A, then write the instructions*/
// Next step, write the instructions for the determine rotate functions.
void	determine_node_steps(t_list *sa, t_list **sb, t_list *node)
{
	t_list	*target;

	if (find_middle(sa, node, &target) == 1)
		determine_rotate_mid_small(sa, sb, target, node);
	else if (get_presort_num(find_large(sa)) < get_presort_num(node))
		determine_rotate_large(sa, sb, find_large(sa), node);
	else if (get_presort_num(find_small(sa)) > get_presort_num(node))
		determine_rotate_mid_small(sa, sb, find_small(sa), node);
	return ;
}

void	determine_turk_sort(t_list **sa, t_list **sb)
{
	t_list	*node;

	node = *sb;
	while (node)
	{
		determine_node_steps(*sa, sb, node);
		node = node->next;
	}
	return ;
}

t_list	*find_cheapest(t_list *stack)
{
	t_list	*node;
	t_d		*stack_data;
	t_d		*node_data;
	
	node = stack;
	node_data = (t_d *)node->content;
	while (stack)
	{
		stack_data = (t_d *)stack->content;
		if (ft_lstsize(stack_data->moves) < ft_lstsize(node_data->moves))
		{
			node = stack;
			node_data = (t_d *)node->content;
		}
		stack = stack->next;
	}
	return (node);
}
