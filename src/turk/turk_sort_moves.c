/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:46:52 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 18:53:17 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_moves(t_list **stack)
{
	t_list	*head;
	t_d		*data;
	t_list	*presort;

	head = *stack;
	while (*stack)
	{
		data = (t_d *)((*stack)->content);
		presort = data->moves;
		if (presort)
		{
			ft_lstclear(&presort, free);
			data->moves = NULL;
		}
		*stack = (*stack)->next;
	}
	*stack = head;
}