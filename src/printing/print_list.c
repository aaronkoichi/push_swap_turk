/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:12:07 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 22:27:10 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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