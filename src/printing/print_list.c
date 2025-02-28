/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:12:07 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 14:15:47 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_both_stacks(t_list *s_a, t_list *s_b)
{
	ft_printf("Stack A: \n");
	while (s_a)
	{
		ft_printf("%d ", get_number_node(s_a));
		s_a = s_a->next;
	}
	ft_printf("\nStack B: \n");
	while (s_b)
	{
		ft_printf("%d ", get_number_node(s_b));
		s_b = s_b->next;
	}
	ft_printf("\n");
}

void	print_each_partition(t_list *stacks)
{
	char	*location;
	int		loc;

	location = NULL;
	ft_printf("Partition number: ");
	while (stacks)
	{
		loc = get_location(stacks);
		ft_printf("%d ", get_par(stacks));
		if (loc == 0)
			location = "MID A";
		else if (loc == 1)
			location = "TOP A";
		else if (loc == 2)
			location = "BOT A";
		else if (loc == 3)
			location = "TOP B";
		else if (loc == 4)
			location = "BOT B";
		else if (loc == 5)
			location = "SORTED";
		ft_printf("%s ", location);
		ft_printf("Number: (%d),", get_number_node(stacks));
		stacks = stacks->next;
	}
	ft_printf("\n");
}
