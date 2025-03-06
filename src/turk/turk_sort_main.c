/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:43:57 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 16:47:11 by zlee             ###   ########.fr       */
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


void	split_push_two(t_list **sa, t_list **sb)
{
	int median;
	int	count;
	t_list	*target;

	median = (ft_lstsize(*sa) -  1) / 2;
	count = 0;
	target = *sa;
	while (count < median && target)
	{
		if (get_presort_num(target) < median)
		{
			if (get_presort_num(*sa) != get_presort_num(target))
				move_to_top(sa, target);
			target = target->next;
			p_stack(sb, sa);
			count++;
		}
		else
			target = target->next;
		reindex_stack(sa, sb);
		
	}
	while (ft_lstsize(*sa) > 3)
		p_stack(sb, sa);
	reindex_stack(sa, sb);
	sort_three(sa);
}

void	turk_sort(t_list **sa, t_list **sb)
{
	t_list	*node;
	int		size;

	size = ft_lstsize(*sa) / 2;
	split_push(sa, sb);
	reindex_stack(sa, sb);
	while (*sb)
	{
		determine_turk_sort(sa, sb);
		node = find_cheapest(*sb);
		execute_push(sa, sb, node);
		free_moves(sb);
		free_moves(sa);
		reindex_stack(sa, sb);
	}
	node = find_small(*sa);
	if (get_index(node) < size)
		r_all(sa, node);
	else
		rr_all(sa, node);
	store_instructions(NULL, 1);
}