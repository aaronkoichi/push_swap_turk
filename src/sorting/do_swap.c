/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:04:08 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 10:48:56 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*find_last_node_chunk(t_list *stk, enum e_loc loc, int p_num)
{
	t_list	*node;

	node = NULL;
	while (stk)
	{
		if (get_location(stk) == loc && get_par(stk) == p_num)
			node = stk;
		stk = stk->next;
	}
	return (node);
}

void	recurse_do_swap(t_list **s_a, t_list **s_b, int p, enum e_loc loc)
{
	t_par_loc	par_loc;
	t_par_loc	next_par_loc;

	// print_each_partition(*s_a);
	// print_each_partition(*s_b);
	reindex_stack(s_a, s_b);
	par_loc = next_large_partition(*s_a, *s_b);
	if (!*s_a || !(is_sorted(*s_a) && !*s_b))
	{
		do_swap_checker(s_a, s_b, par_loc.par, par_loc.loc);
		next_par_loc = next_large_partition(*s_a, *s_b);
		if (par_loc.par == next_par_loc.par && par_loc.loc == next_par_loc.loc)
		{
			ft_printf("Push Back\n");
			push_back(s_a, s_b, par_loc.loc, par_loc.par);
			recurse_do_swap(s_a, s_b, p, loc);
		}
		else
			recurse_do_swap(s_a, s_b, p, loc);
	}
}

t_par_loc	set_loc_mul_par(enum e_loc loc, int par, int mul)
{
	t_par_loc	info;

	info.loc = loc;
	info.par = par;
	info.mul = mul;
	return (info);
}

void	do_swap_checker(t_list **s1, t_list **s2, int p_num, enum e_loc loc)
{
	if (loc == TOP_A || loc == MID_A || loc == BOT_A)
		do_swap_a(s1, s2, p_num, loc);
	else if (loc == TOP_B || loc == BOT_B)
		do_swap_b(s1, s2, p_num, loc);
}

void	do_swap_a(t_list **s_a, t_list **s_b, int p, enum e_loc loc)
{
	t_pivots	pivots;
	static int	multiplier;
	t_par_loc	info;

	ft_printf("do swap a\n");
	if (count_size_par(*s_a, p, loc) <= 0 || srtd_chk(*s_a, loc, p) == 1)
	{
		multiplier = 0;
		return ;
	}
	else if (count_size_par(*s_a, p, loc) <= 3)
	{
		multiplier = 0;
		ft_printf("Sort 2-3\n");
		sort_three_partition(s_a, s_b, p, loc);
		return ;
	}
	else
	{
		find_two_pivot_a(s_a, &pivots, loc, p);
		info = set_loc_mul_par(loc, p, multiplier);
		create_chunk_a(s_a, s_b, pivots, info);
		multiplier++;
		do_swap_a(s_a, s_b, p, loc);
	}
}

void	do_swap_b(t_list **s_a, t_list **s_b, int p, enum e_loc loc)
{
	t_pivots	pivots;
	static int	multiplier;
	t_par_loc	info;
	
	ft_printf("do swap b\n");
	if (count_size_par(*s_b, p, loc) <= 0 || srtd_chk_inv(*s_b, loc, p) == 1)
	{
		multiplier = 0;
		return ;
	}
	else if (count_size_par(*s_b, p, loc) <= 3)
	{
		multiplier = 0;
		sort_three_partition(s_a, s_b, p, loc);
		return ;
	}
	else
	{
		find_two_pivot_b(s_b, &pivots, loc, p);
		info = set_loc_mul_par(loc, p, multiplier);
		create_chunk_b(s_a, s_b, pivots, info);
		multiplier++;
		do_swap_b(s_a, s_b, p, loc);
	}
}
