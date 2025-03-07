/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_assign_inst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:40:58 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:44:05 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_inst_rr_rrr(t_list **checkpoint, int *rolling_a, int *rolling_b)
{
	while (*rolling_a > 0 && *rolling_b > 0)
	{
		ft_lstadd_back(checkpoint, ft_lstnew(ft_strdup("rr\n")));
		(*rolling_a)--;
		(*rolling_b)--;
	}
	while (*rolling_a < 0 && *rolling_b < 0)
	{
		ft_lstadd_back(checkpoint, ft_lstnew(ft_strdup("rrr\n")));
		(*rolling_a)++;
		(*rolling_b)++;
	}
	assign_inst_individual(checkpoint, rolling_a, rolling_b);
}

void	assign_inst_individual(t_list **inst, int *rolling_a, int *rolling_b)
{
	while (*rolling_a > 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("ra\n")));
		(*rolling_a)--;
	}
	while (*rolling_a < 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rra\n")));
		(*rolling_a)++;
	}
	while (*rolling_b > 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rb\n")));
		(*rolling_b)--;
	}
	while (*rolling_b < 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rrb\n")));
		(*rolling_b)++;
	}
}
