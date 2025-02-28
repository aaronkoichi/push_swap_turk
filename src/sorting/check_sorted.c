/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:59:07 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 17:13:00 by zlee             ###   ########.fr       */
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

t_list	*get_first_node_par(t_list *s, enum e_loc loc, int p_num)
{
	while (s)
	{
		if (get_location(s) == loc && get_par(s) == p_num)
			return (s);
		s = s->next;
	}
	return ((t_list *) NULL);
}


int	srtd_chk(t_list *s, enum e_loc loc, int p_num)
{
	t_list	*next_node;

	next_node = get_first_node_par(s, loc, p_num);
	if (!next_node)
		return (1);
	s = next_node->next;
	while (s)
	{
		if (get_location(s) == loc && get_par(s) == p_num)
		{
			if (get_number_node(next_node) > get_number_node(s))
				return (0);
			next_node = s;
		}
		s = s->next;
	}	
	return (1);
}

int	srtd_chk_inv(t_list *s, enum e_loc loc, int p_num)
{
	t_list	*next_node;

	next_node = get_first_node_par(s, loc, p_num);
	if (!next_node)
		return (0);
	s = next_node->next;
	while (s)
	{
		if (get_location(s) == loc && get_par(s) == p_num)
		{
			if (get_number_node(next_node) < get_number_node(s))
				return (0);
			next_node = s;
		}
		s = s->next;
	}	
	return (1);
}
