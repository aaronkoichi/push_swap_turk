/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:12:57 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 08:23:23 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_two_pivot_a(t_list **stk, t_pivots *p, enum e_loc loc, int p_num)
{
	int	counter;
	int	size;

	pre_sort(stk, loc, p_num);
	size = count_size_par(*stk, p_num, loc);
	counter = size / 3;
	p->p1 = get_node_index_par(*stk, counter, loc, p_num);
	p->p2 = get_node_index_par(*stk, size - counter, loc, p_num);
	if (get_number_node(p->p1) > get_number_node(p->p2))
		ft_swap(&p->p1, &p->p2);
	ft_printf("Pivot 1: %d, Pivot 2: %d\n", get_number_node(p->p1), get_number_node(p->p2));
}

void	find_two_pivot_b(t_list **stk, t_pivots *p, enum e_loc loc, int p_num)
{
	int	counter;
	int	size;

	pre_sort(stk, loc, p_num);
	size = count_size_par(*stk, p_num, loc);
	counter = size / 3;
	p->p1 = get_node_index_par(*stk, size - counter, loc, p_num);
	p->p2 = get_node_index_par(*stk, counter + 1, loc, p_num);
	if (get_number_node(p->p1) < get_number_node(p->p2))
		ft_swap(&p->p1, &p->p2);
	ft_printf("Pivot 1: %d, Pivot 2: %d\n", get_number_node(p->p1), get_number_node(p->p2));
}
