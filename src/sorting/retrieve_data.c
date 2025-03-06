/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:18:56 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 14:58:45 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

/*Gets the presorted number*/
int	get_presort_num(t_list *stack)
{
	return (((t_d *)(stack->content))->pre_sort);
}

/*Access the node to write the pre-sorted number.*/
void	set_presort_number(t_list **stack, t_list *node, int number)
{
	t_list *head;

	head = *stack;
	while (*stack)
	{
		if (get_number_node(*stack) == get_number_node(node))
			((t_d *)((*stack)->content))->pre_sort = number;
		*stack = (*stack)->next;
	}
	*stack = head;
}