/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_determine_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:20:22 by zlee              #+#    #+#             */
/*   Updated: 2025/03/03 19:38:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Determine size, determine how to rotate for stack a and b based on the size.*/
void	determine_rotate_mid(t_list *sa, t_list **sb, t_list *target1, t_list *target2)
{
	t_list	*copy;
	int		mid_a;
	int		mid_b;
	
	copy = *sb;
	mid_a = ft_lstsize(sa);
	mid_b = ft_lstsize(*sb);
	if (get_index(target2) < mid_a)
		ra_instructions(sb, target2);
	else
		rra_instructions(sa, sb, target2); 
	
}

void	determine_rotate_small(t_list *sa, t_list **sb, t_list *target1, t_list *target2)
{
	t_list	*copy;
	int		size_a;
	
	copy = *sb;
	size_a = ft_lstsize(sa);
	
}

void	determine_rotate_big(t_list *sa, t_list **sb, t_list *target1, t_list *target2)
{
	t_list	*copy;
	int		size_a;
	
	copy = *sb;
	size_a = ft_lstsize(sa);
	
}