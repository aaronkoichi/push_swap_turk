/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:42:03 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 18:50:15 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	determine_new_loc_par_a(t_list **s1, enum e_loc *new_loc, int *new_par,
		int par)
{
	if (!*s1 || !find_location(*s1, TOP_A))
	{
		*new_par = par;
		*new_loc = TOP_A;
	}
	else
	{
		prepare_stack_a(s1);
		*new_par = get_par(*s1);
		*new_loc = get_location(*s1);
	}
}

void	prepare_stack_a(t_list **s1)
{
	t_list	*temp;

	if (get_location(*s1) != TOP_A)
	{
		temp = get_first_node_par(*s1, TOP_A, get_par_frm_loc(*s1, TOP_A));
		deter_rotate_stk(s1, temp);
	}
}

void	position_stack_b(t_list **s2, enum e_loc loc, int par)
{
	while (!(get_location(*s2) == loc) || !(get_par(*s2) == par))
		r_stack(s2);
}

void	execute_push_to_a(t_list **s1, t_list **s2, enum e_loc new_loc,
		int new_par)
{
	while (*s2 && (get_location(*s2) == get_location(*s2)
			&& get_par(*s2) == get_par(*s2)))
	{
		p_stack(s1, s2);
		change_location(s1, new_loc);
		change_par(s1, new_par);
	}
}

void	push_to_a(t_list **s1, t_list **s2, enum e_loc loc, int par)
{
	enum e_loc new_loc;
	int new_par;

	determine_new_loc_par_a(s1, &new_loc, &new_par, par);
	position_stack_b(s2, loc, par);
	execute_push_to_a(s1, s2, new_loc, new_par);
}