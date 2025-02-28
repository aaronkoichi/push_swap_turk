/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:48:39 by zlee              #+#    #+#             */
/*   Updated: 2025/02/24 18:33:51 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

enum e_loc	get_location(t_list *stack)
{
	return (((t_d *)(stack->content))->location);
}

int	get_par(t_list *stack)
{
	return (((t_d *)(stack->content))->p_num);
}

void	change_par(t_list **stack, int num)
{
	((t_d *)((*stack)->content))->p_num = num;
}

void	change_par_list(t_list **stack, int num)
{
	t_list	*head;

	head = *stack;
	while (*stack != NULL)
	{
		change_par(stack, num);
		stack = &(*stack)->next;
	}
	stack = &head;
}

void	change_location_lst(t_list **s, enum e_loc new, enum e_loc exist, int p)
{
	t_list	*head;
	while(*s)
	{
		if (get_location(*s) == exist && get_par(*s) == p)
			change_location(s, new);
		s = &(*s)->next;
	}
	s = &head;
}
