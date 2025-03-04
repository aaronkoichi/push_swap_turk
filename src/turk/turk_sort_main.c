/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:43:57 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 20:11:44 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Get the median and based off the median,
push the greater numbers on top while the smaller numbers at bottom
of B.*/
void	split_push(t_list **sa, t_list **sb)
{
	int	median;

	median = ft_lstsize(*sa) / 2;
	while (ft_lstsize(*sa) > 3)
	{
		if (get_presort_num(*sa) < median)
		{
			p_stack(sb, sa);
			r_stack(sb);
		}
		else
			p_stack(sb, sa);
	}
	reindex_stack(sa, sb);
	sort_three(sa);
}

void	turk_sort(t_list **sa, t_list **sb)
{
	t_list *node;
	
	split_push(sa, sb);
	reindex_stack(sa, sb);
	determine_turk_sort(sa, sb);
	node = find_cheapest(*sb);
	execute_push(sa, sb, node);
	reindex_stack(sa, sb);
	free_moves(sb);
	free_moves(sa);
	determine_turk_sort(sa, sb);
	node = find_cheapest(*sb);
	execute_push(sa, sb, node);
	reindex_stack(sa, sb);
	// while (*sb)
	// {
	// 	determine_turk_sort(sa, sb);
	// 	node = find_cheapest(*sb);
	// 	execute_push(sa, sb, node);
	// 	reindex_stack(sa, sb);

	// }
	return ;
}