/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_execution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:14:59 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 19:25:00 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Based on the instruction listed by the node, excecute them .*/
void	execute_push(t_list **sa, t_list **sb, t_list *node)
{
	t_d		*data;
	t_list	*instructions;
	
	data = (t_d *)node->content;
	instructions = data->moves;
	while (instructions)
	{
		node_excecution(sa, sb, instructions);
		instructions = instructions->next;
	}	
	return ;
}

void	node_execution(t_list **sa, t_list **sb, t_list *inst)
{
	char	*command;

	command = (char *)inst->content;
	if (command == "ra\n")
		r_stack(sa);
	else if (command == "rb\n")
		r_stack(sb);
	else if (command == "rr\n")
	{
		r_stack(sa);
		r_stack(sb);
	}
	else if (command == "rra\n")
		rr_stack(sa);
	else if (command == "rrb\n")
		rr_stack(sb);
	else if (command == "rrr\n")
	{
		rr_stack(sa);
		rr_stack(sb);
	}
	else
		node_excecution_two(sa, sb, inst);
}

void	node_execution_two(t_list **sa, t_list **sb, t_list *inst)
{
	char	*command;

	command = (char *)inst->content;
	if (command == "pa\n")
		p_stack(sb, sa);
	else if (command == "pb\n")
		p_stack(sa, sb);
	else if (command == "sa\n")
		s_stack(sa);
	else if (command == "sb\n")
		s_stack(sb);
	else if (command == "ss\n")
	{
		s_stack(sa);
		s_stack(sb);
	}
	else
		return ;
}
