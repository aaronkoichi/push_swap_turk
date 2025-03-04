/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:29:32 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 17:44:10 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Determine where to insert the node to stack A, then write the instructions*/
// Next step, write the instructions for the determine rotate functions.
void	determine_node_steps(t_list *sa, t_list **sb, t_list *node)
{
	t_list	*target;

	if (find_middle(sa, node, &target))
		determine_rotate_mid_small(sa, sb, target, node);
	else if (get_presort_num(get_large_node(sa)) < get_presort_num(node))
		determine_rotate_large(sa, sb, get_large_node(sa), node);
	else if (get_presort_num(get_small_node(sa)) > get_presort_num(node))
		determine_rotate_mid_small(sa, sb, get_small_node(sa), node);
	return ;
}

void	determine_turk_sort(t_list **sa, t_list **sb)
{
	t_list	*node;

	node = *sb;
	while (*sb)
	{
		determine_node_steps(*sa, sb, node);
		node = node->next;
	}
	return ;
}

/*push the selected node through the instructions set.*/
void	execute_push(t_list **sa, t_list **sb, t_list *node_tosort)
{
	return ;
}
