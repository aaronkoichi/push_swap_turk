/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:53:21 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 08:51:45 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_par_loc	next_large_partition(t_list *s1, t_list *s2)
{
	t_par_loc	info_top;
	t_par_loc	info_bot;

	info_top = deter_next_partition_top(s1, s2);
	info_bot = deter_next_partition_bot(s1, s2);
	if (info_top.par >= info_bot.par)
		return (info_top);
	else
		return (info_bot);
}

t_par_loc	deter_next_partition_top(t_list *s1, t_list *s2)
{
	t_par_loc	info_top_a;
	t_par_loc	info_top_b;
	
	info_top_a = find_next_partition(s1, TOP_A);
	info_top_b = find_next_partition(s2, TOP_B);
	
	if (info_top_a.par >= info_top_b.par)
		return (info_top_a);
	else
		return (info_top_b);
}

t_par_loc	deter_next_partition_bot(t_list *s1, t_list *s2)
{
	t_par_loc	info_bot_a;
	t_par_loc	info_bot_b;
	
	info_bot_a = find_next_partition(s1, BOT_A);
	info_bot_b = find_next_partition(s2, BOT_B);
	
	if (info_bot_a.par >= info_bot_b.par)
		return (info_bot_a);
	else
		return (info_bot_b);
}

t_par_loc	find_next_partition(t_list *s1, enum e_loc location)
{
	t_par_loc	info;
	
	info.par = -1;
	info.loc = -1;
	if (!s1)
		return (info);
	while (s1)
	{	
		if (get_location(s1) == location && get_par(s1) > info.par)
		{
			info.par = get_par(s1);
			info.loc = location;
		}
		s1 = s1->next;
	}

	return (info);
}

int	count_size_par(t_list *stack, int partition, enum e_loc location)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (get_par(stack) == partition && get_location(stack) == location)
			count++;
		stack = stack->next;
	}
	return (count);
}
