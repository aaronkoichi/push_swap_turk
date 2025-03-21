/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prepare_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:58:35 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:38:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_d	*prep_data(int index, int numbers)
{
	t_d	*data;

	data = malloc(sizeof(t_d));
	data->index = index;
	data->num = numbers;
	data->loc = STK_A;
	data->pre_sort = -1;
	data->moves = NULL;
	return (data);
}

void	free_tdata(t_d *data)
{
	free(data);
}
