/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:31:49 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 11:02:12 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(char **n)
{
	t_list	*s_a;
	t_list	*s_b;
	int		i;

	i = -1;
	s_a = NULL;
	s_b = NULL;
	while (n[++i])
		ft_lstadd_back(&s_a, ft_lstnew(prep_data(i, ft_atoi(n[i]))));
	pre_sort(&s_a);
	if (ft_lstsize(s_a) <= 3)
		sort_two_three(&s_a);
	else if (ft_lstsize(s_a) <= 5)
		sort_four_five(&s_a, &s_b);
	else
		turk_sort(&s_a, &s_b);
	ft_lstclear(&s_a, free);
	ft_lstclear(&s_b, free);
}
