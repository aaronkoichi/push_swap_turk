/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:43:48 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 18:50:07 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	determine_new_loc_par_b(t_list **s2, enum e_loc *new_loc, int *new_par, int par)
{
    if (!*s2 || !find_location(*s2, TOP_B))
    {
        *new_par = par;
        *new_loc = TOP_B;
    }
    else
    {
        prepare_stack_b(s2);
        *new_par = get_par(*s2);
        *new_loc = get_location(*s2);
    }
}

void	prepare_stack_b(t_list **s1)
{
    t_list	*temp;
    
    if (get_location(*s1) != TOP_B)
    {
        temp = get_first_node_par(*s1, TOP_B, get_par_frm_loc(*s1, TOP_B));
        deter_rotate_stk(s1, temp);
    }
}

void	position_stack_a(t_list **s1, enum e_loc loc, int par)
{
    while (!(get_location(*s1) == loc) || !(get_par(*s1) == par))
        r_stack(s1);
}

void	execute_push_to_b(t_list **s1, t_list **s2, enum e_loc new_loc, int new_par)
{
    while (*s1 && (get_location(*s1) == get_location(*s1) && 
        get_par(*s1) == get_par(*s1)))
    {
        p_stack(s2, s1);
        change_location(s2, new_loc);
        change_par(s2, new_par);
    }
}

void	push_to_b(t_list **s1, t_list **s2, enum e_loc loc, int par)
{
    enum e_loc	new_loc;
    int			new_par;

    determine_new_loc_par_b(s2, &new_loc, &new_par, par);
    position_stack_a(s1, loc, par);
    execute_push_to_b(s1, s2, new_loc, new_par);
}