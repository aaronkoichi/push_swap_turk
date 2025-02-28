/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three_par.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:47:02 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 10:47:56 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// there could be the issue where the TOP or BOT are at below.
// find the node then rotate it upwards until it is at the top of the stack.
void	sort_two_b(t_list **stack, int p_num, enum e_loc location)
{
	t_list	*temp;

	temp = NULL;
	if (get_location(*stack) != location || get_par(*stack) != p_num)
	{
		temp = get_first_node_par(*stack, location, p_num);
		deter_rotate_stk(stack, temp);
	}
	if (get_location((*stack)->next) != location
		|| get_par((*stack)->next) != p_num)
		rr_stack(stack);
	sort_two_inv(stack);
}

void	sort_two_a(t_list **stack, int p_num, enum e_loc location)
{
	t_list	*temp;

	temp = NULL;
	if (get_location(*stack) != location || get_par(*stack) != p_num)
	{
		temp = get_first_node_par(*stack, location, p_num);
		deter_rotate_stk(stack, temp);
	}
	if (get_location((*stack)->next) != location
		|| get_par((*stack)->next) != p_num)
		rr_stack(stack);
	sort_two(stack);
}

void	sort_three_a(t_list **s1, t_list **s2, int p_num, enum e_loc location)
{
	t_list		*small_node;
	t_list		*temp;
	enum e_loc	loc;
	int			par;

	small_node = get_small_node(*s1, p_num, location);
	temp = NULL;
	loc = get_location(*s1);
	par = get_par(*s1);
	if (get_location(*s1) != location && get_par(*s1) != p_num)
	{
		temp = get_first_node_par(*s1, location, p_num);
		deter_rotate_stk(s1, temp);
	}
	r_rr_top(s1, s2, small_node, p_num);
	reindex_stack(s1, s2);
	sort_two_a(s1, p_num, location);
	p_stack(s1, s2);
	change_location(s1, loc);
	change_par(s1, par);
}

void	sort_three_b(t_list **s1, t_list **s2, int p_num, enum e_loc location)
{
	t_list		*small_node;
	t_list		*temp;
	enum e_loc	loc;
	int			par;

	small_node = get_large_node(*s2, p_num, location);
	temp = NULL;
	ft_printf("sort 3 b\n");
	if (get_location(*s2) != location && get_par(*s2) != p_num)
	{
		temp = get_first_node_par(*s2, location, p_num);
		deter_rotate_stk(s2, temp);
	}
	loc = get_location(*s2);
	par = get_par(*s2);
	r_rr_top(s1, s2, small_node, p_num);
	reindex_stack(s1, s2);
	sort_two_b(s2, p_num, location);
	p_stack(s2, s1);
	change_location(s2, loc);
	change_par(s1, par);
}

void	sort_three_partition(t_list **s1, t_list **s2, int p, enum e_loc loc)
{
	if (loc == TOP_A || loc == MID_A || loc == BOT_A)
	{
		if (count_size_par(*s1, p, loc) == 1)
			return ;
		if (count_size_par(*s1, p, loc) == 2)
			sort_two_a(s1, p, loc);
		else
			sort_three_a(s1, s2, p, loc);
	}
	else
	{
		if (count_size_par(*s2, p, loc) == 1)
			return ;
		if (count_size_par(*s2, p, loc) == 2)
			sort_two_b(s2, p, loc);
		else
			sort_three_b(s1, s2, p, loc);
	}
}
