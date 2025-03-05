/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:50:41 by zlee              #+#    #+#             */
/*   Updated: 2025/03/05 16:11:24 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	compare_rotate(char *content)
{
	if (!ft_strcmp(content, "ra\n", 3) || !ft_strcmp(content, "rb\n", 3)
		|| !ft_strcmp(content, "rra\n", 4) || !ft_strcmp(content, "rrb\n", 4))
		return (0);
	else
		return (1);
}

void	optimize_instructions(t_list **inst)
{
	t_list	*checkpoint;
	t_list	*new_list;
	int		rolling_a;
	int		rolling_b;

	rolling_a = 0;
	rolling_b = 0;
	checkpoint = NULL;
	new_list = NULL;
	while (inst)
	{
		checkpoint = *inst;
		while ((*inst)->next && !compare_rotate((*inst)->next->content))
			(*inst) = (*inst)->next;
		trim_inst(checkpoint, &rolling_a, &rolling_b);
		if (!compare_rotate(checkpoint->content))
			checkpoint = assign_inst_rr_rrr(&rolling_a, &rolling_b);
		ft_lstadd_back(new_list, checkpoint);
		(*inst) = (*inst)->next;
	}
	ft_lstclear(inst, free);
	*inst = new_list;
}

t_list	*assign_inst_rr_rrr(int *rolling_a, int *rolling_b)
{
	t_list	*new_inst;

	new_inst = NULL;
	while
		(*rolling_a > 0 && *rolling_b > 0)
		{
			ft_lstadd_back(new_inst, ft_strdup("rr\a"));
			(*rolling_a)--;
			(*rolling_b)--;
		}
	while (*rolling_a < 0 && *rolling_b < 0)
	{
		ft_lstadd_back(new_inst, ft_stedup("rrr\a"));
		(*rolling_a)++;
		(*rolling_b)++;
	}
	return (assign_inst_individual(new_inst, rolling_a, rolling_b));
}

t_list	*assign_inst_indiviual(t_list *inst, int *rolling_a, int *rolling_b)
{
	while (*rolling_a > 0)
	{
		ft_lstadd_back(inst, ft_strdup("ra\a"));
		(*rolling_a)--;
	}
	while (*rolling_a < 0)
	{
		ft_lstadd_back(inst, ft_strdup("rra\n"));
		(*rolling_a)++;
	}
	while (*rolling_b > 0)
	{
		ft_lstadd_back(inst, ft_strdup("rb\n"));
		(*rolling_b)--;
	}
	while (*rolling_b > 0)
	{
		ft_lstadd_back(inst, ft_strdup("rrb\n"));
		(*rolling_b)++;
	}
	return (inst);
}

void	trim_inst(t_list *inst, int *rolling_a, int *rolling_b)
{

	while (inst && (!compare_rotate(inst->content)))
	{
		if (!ft_strcmp(inst->content, "ra\n", 3))
			(*rolling_a)++;
		else if (!ft_strcmp(inst->content, "rb\n", 3))
			(*rolling_b)++;
		else if (!ft_strcmp(inst->content, "rra\n", 4))
			(*rolling_a)--;
		else if (!ft_strcmp(inst->content, "rrb\n", 4))
			(*rolling_b)--;
		inst = inst->next;
	}
}
