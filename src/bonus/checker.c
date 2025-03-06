/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:37:21 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 17:49:42 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../get_next_line/get_next_line.h"

void	push_swap(char **n)
{
	t_list	*s_a;
	t_list	*s_b;
	int		i;
	char	*string;

	i = -1;
	s_a = NULL;
	s_b = NULL;
	while (n[++i])
		ft_lstadd_back(&s_a, ft_lstnew(prep_data(i, ft_atoi(n[i]))));
	pre_sort(&s_a);
	string = get_next_line(0);
	while (string != NULL)
		

	if (!s_b && is_sorted(s_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&s_a, free);
	ft_lstclear(&s_b, free);
}
