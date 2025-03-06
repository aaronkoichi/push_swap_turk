/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:43:31 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 13:41:24 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Function created so it will not overcomplicate things*/
void	sort_two_three(t_list **s_a)
{
	if (ft_lstsize(*s_a) == 2)
		sort_two(s_a);
	else
		sort_three(s_a);
}

void	sort_two(t_list **s_a)
{
	if (get_number_node(*s_a) > get_number_node((*s_a)->next))
		s_stack(s_a);
}

void	sort_three(t_list **s_a)
{
	while (is_sorted(*s_a) == 0)
	{
		if (get_number_node(*s_a) > get_number_node((*s_a)->next))
			s_stack(s_a);
		if (get_number_node((*s_a)->next) >
			get_number_node((*s_a)->next->next))
			rr_stack(s_a);
	}
}
