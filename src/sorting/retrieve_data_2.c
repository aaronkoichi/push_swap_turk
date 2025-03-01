/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:48:39 by zlee              #+#    #+#             */
/*   Updated: 2025/03/01 22:38:56 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Gets the location of the node*/
enum e_stk	get_location(t_list *stack)
{
	return (((t_d *)(stack->content))->loc);
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
