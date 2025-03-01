/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:42:18 by zlee              #+#    #+#             */
/*   Updated: 2025/03/01 23:00:42 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Pre-sort the linked list using  */
void	pre_sort(t_list **stack)
{
	t_list	*head;
	t_list	*temp;
	int		counter;

	head = *stack;
	temp = *stack;
	while (temp)
	{
		counter = 0;
		while (*stack)
		{
			if (get_number_node(temp) > get_number_node(*stack))
				counter++;
			(*stack) = (*stack)->next;
		}
		*stack = head;
		set_presort_number(stack, temp, counter);
		temp = temp->next;
	}
}