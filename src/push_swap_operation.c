/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:20:15 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 14:37:16 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_stack(t_list **stacks)
{
	t_list	*first;
	t_list	*second;

	if (!stacks || !(*stacks) || !((*stacks)->next))
		return ;
	if (get_location(*stacks) == STK_A)
		// ft_printf("sa\n");
		store_instructions("sa\n", 0);
	else
		store_instructions("sb\n", 0);
		// ft_printf("sb\n");
	first = *stacks;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stacks = second;
}
void	p_stack(t_list	**s_a, t_list	**s_b)
{
	t_list *current_node;

	if (!*s_b)
		return ;
	current_node = *(s_b);
	if (get_location(*s_b) == STK_A)
	 {
		change_location(s_b, STK_B);
		store_instructions("pb\n", 0);
		// ft_printf("pb\n");
	 }
	else
	{
		change_location(s_b, STK_A);
		store_instructions("pa\n", 0);
		// ft_printf("pa\n");
	}
	if ((*s_b)->next == NULL)
		*s_b = NULL;
	else
		*s_b = (*s_b)->next;
	current_node->next = (*s_a);
	*s_a = current_node;
}

void	r_stack(t_list **stacks)
{
	t_list	*first;

	if (!stacks || !*stacks || !(*stacks)->next)
		return ;
	if (get_location(*stacks) == STK_A)
		// ft_printf("ra\n");
		store_instructions("ra\n", 0);
	else
		store_instructions("rb\n", 0);
		// ft_printf("rb\n");
	first = *stacks;
	(*stacks) = (*stacks)->next;
	first->next = NULL;
	ft_lstadd_back(stacks, first);
}

void	rr_stack(t_list **stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stacks || !*stacks || !(*stacks)->next)
		return ;

	if (get_location(*stacks) == STK_A)
		// ft_printf("rra\n");
		store_instructions("rra\n", 0);
	else
		// ft_printf("rrb\n");
		store_instructions("rrb\n", 0);
	tmp = *stacks;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp2->next = *stacks;
	tmp->next = NULL;
	*stacks = tmp2;

}
