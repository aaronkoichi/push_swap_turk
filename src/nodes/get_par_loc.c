/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_par_loc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:26:29 by zlee              #+#    #+#             */
/*   Updated: 2025/02/24 13:24:42 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_par_loc(t_list *s1, int p_num, enum e_loc loc)
{
	while (s1)
	{
		if (get_par(s1) == p_num && get_location(s1) == loc)
			return (1);
		s1 = s1->next;
	}
	return (0);
}

t_list *get_loc_par_node(t_list *s1, int p_num, enum e_loc loc)
{
	while(s1)
	{
		if (get_par(s1) == p_num && get_location(s1) == loc)
			return (s1);
		s1 = s1->next;
	}
	return (0);
}
