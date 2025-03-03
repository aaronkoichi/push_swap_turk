/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:29:32 by zlee              #+#    #+#             */
/*   Updated: 2025/03/03 11:59:26 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Determine where to insert the node to stack A, then write the instructions*/
// Next step, write the instructions for the determine rotate functions.
void	determine_node_steps(t_list *sa, t_list **sb)

{
	t_list	*target1;
	t_list	*target2;

	if (find_middle(sa, *sb, &target1, &target2) == 1)
	 {
		determine_rotate_mid(sa, sb, &target1, &target2);
	 }
	else if (find_small(sa, &target1, &target2) == 1)
	{
		determine_rotate_small(sa, sb, &target1, &target2);
	}
	else
	 	determine_rotate_big(sa, &target1, &target2);
	return ;
}
void	determine_turk_sort(t_list **sa, t_list **sb)
{
	while (*sb)
	{
		determine_node_steps(*sa, sb);
		(*sb) = (*sb)->next;
	}
	return ;
}

/*push the selected node through the instructions set.*/
void	execute_push(t_list **sa, t_list **sb, t_list *node_tosort)
{
	return ;
}