/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:20:15 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 11:31:54 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_stack(t_list **stacks)
{
	t_list	*first;
	t_list	*second;

	if (!stacks || !(*stacks) || !((*stacks)->next))
		return ;
	if (get_location(*stacks) == TOP_A || get_location(*stacks) == MID_A
	|| get_location(*stacks) == BOT_A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	first = *stacks;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stacks = second;
	// print_each_partition(*stacks);
	// ft_printf("\n");
}

void	p_stack(t_list	**s_a, t_list	**s_b)
{
	t_list *current_node;

	if (!*s_b)
		return ;
	current_node = *(s_b);
	if (get_location(*s_b) == TOP_A || get_location(*s_b) == MID_A
		|| get_location(*s_b) == BOT_A)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
	if ((*s_b)->next == NULL)
		*s_b = NULL;
	else
		*s_b = (*s_b)->next;
	current_node->next = (*s_a);
	*s_a = current_node;
	// print_each_partition(*s_a);
	// print_each_partition(*s_b);
	// ft_printf("\n");
}

void	r_stack(t_list **stacks)
{
	t_list	*last;
	t_list	*first;
	t_list	*temp;

	if (!stacks || !*stacks || !(*stacks)->next)
		return ;
	if (get_location(*stacks) == TOP_A || get_location(*stacks) == MID_A
	|| get_location(*stacks) == BOT_A)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	first = *stacks;
	(*stacks) = (*stacks)->next;
	first->next = NULL;
	ft_lstadd_back(stacks, first);
	// print_each_partition(*stacks);
	// ft_printf("\n");
}

void	rr_stack(t_list **stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stacks || !*stacks || !(*stacks)->next)
		return ;

	if (get_location(*stacks) == TOP_A || get_location(*stacks) == MID_A
	|| get_location(*stacks) == BOT_A)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	tmp = *stacks;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp2->next = *stacks;
	tmp->next = NULL;
	*stacks = tmp2;
	// print_each_partition(*stacks);
	// ft_printf("\n");
}
