/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:59:07 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 22:36:08 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*This is to check if the first number and the next number is sorted correctly
  in the stack or not*/
int	is_sorted(t_list *s)
{
	while (s->next)
	{
		if (((t_d *)(s->content))->num > ((t_d *)(s->next->content))->num)
			return (0);
		s = s->next;
	}
	return (1);
}