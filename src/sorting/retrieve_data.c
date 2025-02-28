/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:18:56 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 22:32:58 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	change_location(t_list **stack, enum e_stk loc)
{
	((t_d *)((*stack)->content))->loc = loc;
}

int	get_number_node(t_list *s)
{
	return ((int)((t_d *)(s->content))->num);
}

int	get_index(t_list *s)
{
	return ((int)((t_d *)(s->content))->index);
}

void	reindex_stack(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	int	i;
	i = 0;
	head = *stack_a;
	while (*stack_a != NULL)
	{
		((t_d *)((*stack_a)->content))->index = i++;
		stack_a = &(*stack_a)->next;
	}
	stack_a = &head;
	head = *stack_b;
	i = 0;
	while (*stack_b != NULL)
	{
		((t_d *)((*stack_b)->content))->index = i++;
		stack_b = &(*stack_b)->next;
	}
	stack_b = &head;
}
