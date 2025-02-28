/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:12 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 18:45:12 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_back(t_list **s1, t_list **s2, enum e_loc loc, int par)
{
	if (loc == TOP_B || loc == BOT_B)
		push_to_a(s1, s2, loc, par);
	else
		push_to_b(s1, s2, loc, par);
	reindex_stack(s1, s2);
}

int	find_location(t_list *stacks, enum e_loc loc)
{
	while (stacks)
	{
		if (get_location(stacks) == loc)
			return (1);
		stacks = stacks->next;
	}
	return (0);
}

int	get_par_frm_loc(t_list *stacks, enum e_loc loc)
{
	while (stacks)
	{
		if (get_location(stacks) == loc)
			return (get_par(stacks));
		stacks = stacks->next;
	}
	return (-1);
}