/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:44 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 14:41:58 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	deter_rotate_stk(t_list **stk, t_list *target_n)
{
	if (get_index(target_n) < ft_lstsize(*stk) / 2)
		r_stk(stk, target_n);
	else
		rr_stk(stk, target_n);
}

void	r_stk(t_list **stk, t_list *target_n)
{
	while (get_number_node(*stk) != get_number_node(target_n))
		r_stack(stk);
}

void	rr_stk(t_list **stk, t_list *target_n)
{
	while (get_number_node(*stk) != get_number_node(target_n))
		rr_stack(stk);
}