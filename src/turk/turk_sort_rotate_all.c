/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_rotate_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:12:43 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:52:56 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	r_all(t_list **stack, t_list *head)
{
	while (get_number_node(head) != get_number_node(*stack))
		r_stack(stack);
}

void	rr_all(t_list **stack, t_list *head)
{
	while (get_number_node(head) != get_number_node(*stack))
		rr_stack(stack);
}
