/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:31:49 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 17:11:32 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(char **n)
{
	t_list	*s_a;
	t_list	*s_b;
	t_d		*temp_data;
	int		i;

	i = -1;
	s_a = NULL;
	s_b = NULL;
	while (n[++i])
		ft_lstadd_back(&s_a, ft_lstnew(prep_data(i, ft_atoi(n[i]), 1, 0)));
	// ft_printf("partition: %d\n", get_par(s_a));
	// print_both_stacks(s_a, s_b);
	if (ft_lstsize(s_a) == 3)
		sort_two_three(&s_a);
	else
		recurse_do_swap(&s_a, &s_b, get_par(s_a), MID_A);
	ft_lstclear(&s_a, free);
	ft_lstclear(&s_b, free);
}
