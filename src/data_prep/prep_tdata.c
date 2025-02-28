/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_tdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:58:35 by zlee              #+#    #+#             */
/*   Updated: 2025/02/27 17:14:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_d	*prep_data(int index, int numbers, enum e_loc location, int p)
{
	t_d	*data;

	data = malloc(sizeof(t_d));
	data->index = index;
	data->num = numbers;
	data->location = location;
	data->p_num = p;
	data->pre_sort = -1;
	return (data);
}

void	free_tdata(t_d *data)
{
	free(data);
}

t_d *dup_data(t_d *content)
{
	t_d *data;

	data = malloc(sizeof(t_d));
	data->index = content->index;
	data->num = content->num;
	data->location = content->location;
	data->p_num = content->p_num;
	return (data);
}
