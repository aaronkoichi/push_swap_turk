/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_rotate_inst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:15:32 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 18:15:19 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra_instructions(t_list **sb, t_list *target)
{
	int counter;

	counter = -1;
	while (++counter < get_index(target))
		ft_lstadd_back(&((t_d *)((*sb)->content))->moves,
			ft_lstnew(ft_strdup("ra\n")));
}

void	rra_instructions(t_list *sa, t_list **sb, t_list *target)
{
	int counter;

	counter = ft_lstsize(sa) + 1;
	while (--counter > get_index(target))
		ft_lstadd_back(&((t_d *)((*sb)->content))->moves,
			ft_lstnew(ft_strdup("rra\n")));
}

void	rb_instructions(t_list **sb, t_list *node)
{
	int counter;

	counter = -1;
	while (++counter < get_index(node))
		ft_lstadd_back(&((t_d *)((*sb)->content))->moves,
			ft_lstnew(ft_strdup("rb\n")));
}

void	rrb_instructions(t_list *stack, t_list **sb, t_list *node)
{
	int counter;

	counter = ft_lstsize(stack) + 1;
	while (--counter > get_index(node))
		ft_lstadd_back(&((t_d *)((*sb)->content))->moves,
			ft_lstnew(ft_strdup("rrb\n")));
}