/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:16:54 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 22:55:14 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_list **s1, t_list **s2)
{
	t_list	*temp;

	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

// void	ra_pb_top(t_list **s_a, t_list **s_b, t_list *node, int partition)
// {
// 	int	i;
// 	int	index;

// 	index = get_index(node);
// 	i = -1;
// 	while (++i < index)
// 	{
// 		r_stack(&*s_a);
// 	}
// 	p_stack(s_b, s_a);
// 	change_location(s_b, TOP_B);
// 	change_par(s_b, partition);
// }

// void	rra_pb_top(t_list **s_a, t_list **s_b, t_list *node, int partition)
// {
// 	int	i;
// 	int	index;

// 	index = get_index(node);
// 	i = ft_lstsize(*s_a) + 1;
// 	while (--i > index)
// 		rr_stack(&*s_a);
// 	p_stack(s_b, s_a);
// 	change_location(s_b, TOP_B);
// 	change_par(s_b, partition);
// }

// void	ra_pb_bot(t_list **s_a, t_list **s_b, t_list *node, int partition)
// {
// 	int	i;
// 	int	index;

// 	index = get_index(node);
// 	i = -1;
// 	while (++i < index)
// 		r_stack(s_a);
// 	p_stack(s_b, s_a);
// 	change_location(s_b, BOT_B);
// 	change_par(s_b, partition);
// 	r_stack(s_b);
// }

// void	rra_pb_bot(t_list **s_a, t_list **s_b, t_list *node, int partition)
// {
// 	int	i;
// 	int	index;

// 	index = get_index(node);
// 	i = ft_lstsize(*s_a) + 1;
// 	while (--i > index)
// 		rr_stack(&*s_a);
// 	p_stack(s_b, s_a);
// 	change_location(s_b, BOT_B);
// 	change_par(s_b, partition);
// 	r_stack(s_b);
// }
