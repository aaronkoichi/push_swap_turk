/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:51 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 18:43:16 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_each_instructions(t_list *stack)
{
	t_list	*presort;

	while (stack)
	{
		presort = ((t_d *)(stack->content))->moves;
		ft_printf("Number (%d): ", get_number_node(stack));
		while (presort)
		{
			ft_printf("%s,", (char *)presort->content);
			presort = presort->next;
		}
		ft_printf("\n\n");
		stack = stack->next;
	}
}

void	print_stack(t_list *sa)
{
	ft_printf("Stack A: ");
	while (sa)
	{
		ft_printf("%d ", get_number_node(sa));
		sa = sa->next;
	}
	ft_printf("\n");
}

void	print_presort(t_list *sa)
{
	ft_printf("Stack A: ");
	while (sa)
	{
		ft_printf("%d ", get_presort_num(sa));
		sa = sa->next;
	}
	ft_printf("\n");
}