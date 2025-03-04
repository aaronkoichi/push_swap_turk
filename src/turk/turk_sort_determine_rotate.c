/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_determine_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:20:22 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 17:41:55 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Determine size, determine how to rotate for stack a and b based on the size.*/
void	determine_rotate_mid_small(t_list *sa, t_list **sb, t_list *target,
		t_list *node)
{
	int		mid_a;
	int		mid_b;
	t_list	*head;

	head = *sb;
	mid_a = ft_lstsize(sa);
	mid_b = ft_lstsize(*sb);
	while (get_presort_num(*sb) != get_presort_num(node))
		(*sb) = (*sb)->next;
	if (get_index(target) < mid_a)
		ra_instructions(sb, target);
	else
		rra_instructions(sa, sb, target);
	if (get_index(node) < mid_b)
		rb_instructions(sb, node);
	else
		rrb_instructions(head, sb, node);
	ft_lstadd_back(((t_d *)((*sb)->content))->moves,
		ft_lstnew(ft_strdup("pa\n")));
	*sb = head;
}

void	determine_rotate_large(t_list *sa, t_list **sb, t_list *target,
		t_list *node)
{
	int		mid_a;
	int		mid_b;
	t_list	*head;

	head = *sb;
	mid_a = ft_lstsize(sa);
	mid_b = ft_lstsize(*sb);
	while (get_presort_num(*sb) != get_presort_num(node))
		(*sb) = (*sb)->next;
	if (get_index(target) < mid_a)
		ra_instructions(sb, target);
	else
		rra_instructions(sa, sb, target);
	ft_lstadd_back(((t_d *)((*sb)->content))->moves,
		ft_lstnew(ft_strdup("ra\n")));
	if (get_index(node) < mid_b)
		rb_instructions(sb, node);
	else
		rrb_instructions(head, sb, node);
	ft_lstadd_back(((t_d *)((*sb)->content))->moves,
		ft_lstnew(ft_strdup("pa\n")));
	*sb = head;
}
