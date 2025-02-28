/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:16:45 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 10:38:17 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	prc_chunk_to_a(t_list **s1, t_list **s2, t_pivots pivots, t_info info)
{
	if (s2 && get_number_node(info.n_ts) > get_number_node(pivots.p1)
		|| get_number_node(info.n_ts) == get_number_node(pivots.p1))
		r_rr_bot(s1, s2, info.n_ts, get_par(info.n_ts) + info.multiplier + 1);
	else if (get_number_node(info.n_ts) < get_number_node(pivots.p2)
		|| get_number_node(info.n_ts) == get_number_node(pivots.p2))
		;
	else
		r_rr_top(s1, s2, info.n_ts, get_par(info.n_ts) + info.multiplier + 1);
}

void	prc_chunk_to_b(t_list **s1, t_list **s2, t_pivots pivots, t_info info)
{
	if (s1 && (get_number_node(info.n_ts) < get_number_node(pivots.p1)
			|| get_number_node(info.n_ts) == get_number_node(pivots.p1)))
		r_rr_bot(s1, s2, info.n_ts, get_par(info.n_ts) + info.multiplier + 1);
	else if (s1 && (get_number_node(info.n_ts) == get_number_node(pivots.p2)
			|| get_number_node(info.n_ts) > get_number_node(pivots.p2)))
		;
	else
		r_rr_top(s1, s2, info.n_ts, get_par(info.n_ts) + info.multiplier + 1);
}
