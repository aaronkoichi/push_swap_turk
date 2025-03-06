/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data_location.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:42:29 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 13:42:40 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	change_location(t_list **stack, enum e_stk loc)
{
	((t_d *)((*stack)->content))->loc = loc;
}

enum e_stk	get_location(t_list *stack)
{
	return (((t_d *)(stack->content))->loc);
}