/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_operation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:43:47 by zlee              #+#    #+#             */
/*   Updated: 2025/02/17 14:47:55 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	r_rr_top(t_list **s1, t_list **s2, t_list *node, int partition)
{
	int	size;

	size = 0;
	if (get_location(node) == TOP_A || get_location(node) == MID_A ||
	 get_location(node) == BOT_A)
		{
			size = ft_lstsize(*s1);
			if (get_index(node) < size / 2)
				ra_pb_top(s1, s2, node, partition);
			else
				rra_pb_top(s1, s2, node, partition);
		}
	else
		{
			size = ft_lstsize(*s2);
			if (get_index(node) < size / 2)
				rb_pa_top(s1, s2, node, partition);
			else
				rrb_pa_top(s1, s2, node, partition);
	}
}

void	r_rr_bot(t_list **s1, t_list **s2, t_list *node, int partition)
{
	int	size;

	size = 0;
	if (get_location(node) == TOP_A || get_location(node) == MID_A ||
	 get_location(node) == BOT_A)
		{
			size = ft_lstsize(*s1);
			if (get_index(node) < size / 2)
				ra_pb_bot(s1, s2, node, partition);
			else
				rra_pb_bot(s1, s2, node, partition);
		}
	else
		{
			size = ft_lstsize(*s2);
			if (get_index(node) < size / 2)
				rb_pa_bot(s1, s2, node, partition);
			else
				rrb_pa_bot(s1, s2, node, partition);
	}
}
