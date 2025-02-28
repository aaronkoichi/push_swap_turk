/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:26:00 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 14:38:02 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	create_chunk_a(t_list **s1, t_list **s2, t_pivots pvts, t_par_loc plm)
{
	int		size;
	int		i;
	t_list	*node_ts;
	t_list	*next_node;
	t_info	info;

	node_ts = *s1;
	size = ft_lstsize(*s1);
	i = -1;
	while (++i < size)
	{
		if (node_ts == NULL)
			next_node = NULL;
		else
			next_node = node_ts->next;
		info.multiplier = plm.mul;
		info.n_ts = node_ts;
		if (plm.loc == get_location(node_ts) && plm.par == get_par(node_ts))
			prc_chunk_to_b(s1, s2, pvts, info);
		node_ts = next_node;
		reindex_stack(s1, s2);
	}
}

void	create_chunk_b(t_list **s1, t_list **s2, t_pivots pvts, t_par_loc plm)
{
	int		size;
	int		i;
	t_list	*node_ts;
	t_list	*next_node;
	t_info	info;

	node_ts = *s2;
	size = ft_lstsize(*s2);
	i = -1;
	while (++i < size)
	{
		if (node_ts == NULL)
			break ;
		else
			next_node = node_ts->next;
		info.multiplier = plm.mul;
		info.n_ts = node_ts;
		if (plm.loc == get_location(node_ts) && plm.par == get_par(node_ts))
			prc_chunk_to_a(s1, s2, pvts, info);
		node_ts = next_node;
		reindex_stack(s1, s2);
	}
}
