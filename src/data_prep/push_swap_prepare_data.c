/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prepare_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:58:35 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 22:35:44 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_d	*prep_data(int index, int numbers, enum e_stk loc)
{
	t_d	*data;

	data = malloc(sizeof(t_d));
	data->index = index;
	data->num = numbers;
	data->loc = loc;
	data->pre_sort = -1;
	return (data);
}

void	free_tdata(t_d *data)
{
	free(data);
}