/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:42:18 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 17:02:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


int get_presort_num(t_list *stack)
{
	return (((t_d *)(stack->content))->pre_sort);
}

t_list	*get_node_index_par(t_list *stack, int index, enum e_loc loc, int par)
{
	while (stack)
	{
		if (get_location(stack) == loc && (get_par(stack) == par)
			&& get_presort_num(stack) == index)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
void	set_presort_number(t_list **stack, t_list *node, int number)
{
	t_list	*head;

	head = *stack;
	while (*stack)
	{
		if (get_number_node(*stack) == get_number_node(node))
			((t_d *)((*stack)->content))->pre_sort = number;
		*stack = (*stack)->next;
	}
	*stack = head;
}

void	pre_sort(t_list **stack, enum e_loc loc, int partition)
{
	int counter;
	t_list *current_node;
	t_list *temp;
	t_list *to_set;

	counter = 0;
	temp = *stack;
	current_node = get_first_node_par(*stack, loc, partition);
	while (current_node)
	{
		while (temp)
		{
			if (get_location(temp) == loc && get_par(temp) == partition)
				if (get_number_node(current_node) < get_number_node(temp))
					counter++;
			temp = temp->next;
		}
		temp = *stack;
		set_presort_number(stack, current_node, counter);
		counter = 0;
		current_node = get_first_node_par(current_node->next, loc, partition);
	}
}