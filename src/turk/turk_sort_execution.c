/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_execution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:14:59 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:33:52 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Based on the instruction listed by the node, excecute them .*/
void	execute_push(t_list **sa, t_list **sb, t_list *node)
{
	while (node)
	{
		node_execution(sa, sb, node);
		node = node->next;
	}
	return ;
}

void	node_execution(t_list **sa, t_list **sb, t_list *inst)
{
	char	*command;

	command = (char *)inst->content;
	if (!ft_strncmp(command, "ra\n", 3))
		r_stack(sa);
	else if (!ft_strncmp(command, "rb\n", 3))
		r_stack(sb);
	else if (!ft_strncmp(command, "rr\n", 3))
	{
		r_stack(sa);
		r_stack(sb);
	}
	else if (!ft_strncmp(command, "rra\n", 4))
		rr_stack(sa);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rr_stack(sb);
	else if (!ft_strncmp(command, "rrr\n", 4))
	{
		rr_stack(sa);
		rr_stack(sb);
	}
	else
		node_execution_two(sa, sb, inst);
}

void	node_execution_two(t_list **sa, t_list **sb, t_list *inst)
{
	char	*command;

	command = (char *)inst->content;
	if (!ft_strncmp(command, "pb\n", 3))
		p_stack(sb, sa);
	else if (!ft_strncmp(command, "pa\n", 3))
		p_stack(sa, sb);
	else if (!ft_strncmp(command, "sa\n", 3))
		s_stack(sa);
	else if (!ft_strncmp(command, "sb\n", 3))
		s_stack(sb);
	else if (!ft_strncmp(command, "ss\n", 3))
	{
		s_stack(sa);
		s_stack(sb);
	}
	else
		ft_printf("Not Working: %s\n", command);
}
