/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:30:43 by zlee              #+#    #+#             */
/*   Updated: 2025/03/04 18:44:44 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// t_list	*get_small_node(t_list *s1, int p_num, enum e_loc loc)
// {
// 	int		active;
// 	t_list	*small_node;

// 	small_node = get_loc_par_node(s1, p_num, loc);
// 	while (s1)
// 	{
// 		if (get_number_node(s1) < get_number_node(small_node)
// 			&& get_par(s1) == p_num && get_location(s1) == loc)
// 			small_node = s1;
// 		s1 = s1->next;
// 	}
// 	return (small_node);
// }

// t_list	*get_large_node(t_list *s1, int p_num, enum e_loc loc)
// {
// 	t_list	*large_node;

// 	large_node = get_first_node_par(s1, loc, p_num);
// 	while (s1)
// 	{
// 		if (get_number_node(s1) > get_number_node(large_node)
// 			&& get_par(s1) == p_num && get_location(s1) == loc)
// 			large_node = s1;
// 		s1 = s1->next;
// 	}
// 	return (large_node);
// }
