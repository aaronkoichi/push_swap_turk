/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_determine_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:27:57 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:50:49 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*determine if there is a middle point for the node to be pushed.*/
int	find_middle(t_list *sa, t_list *node, t_list **dst2)
{
	t_list	*dst1;

	dst1 = sa;
	*dst2 = sa->next;
	while (dst1 && *dst2)
	{
		if (get_presort_num(node) > get_presort_num(dst1)
			&& get_presort_num(node) < get_presort_num(*dst2))
			return (1);
		dst1 = (dst1)->next;
		*dst2 = (*dst2)->next;
	}
	dst1 = ft_lstlast(sa);
	*dst2 = sa;
	if (get_presort_num(node) > get_presort_num(dst1)
		&& get_presort_num(node) < get_presort_num(*dst2))
		return (1);
	dst1 = NULL;
	*dst2 = NULL;
	return (0);
}

/*Used when unable to find the middle point to push the number.*/
t_list	*find_small(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (stack)
	{
		if (get_presort_num(temp) > get_presort_num(stack))
			temp = stack;
		stack = stack->next;
	}
	return (temp);
}

/*Used when unable to find the middle point to push the number.*/
t_list	*find_large(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (stack)
	{
		if (get_presort_num(temp) < get_presort_num(stack))
			temp = stack;
		stack = stack->next;
	}
	return (temp);
}
