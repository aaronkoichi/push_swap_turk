/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_numbers_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:09:12 by zlee              #+#    #+#             */
/*   Updated: 2025/03/05 09:32:27 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	check_dup(char **argv)
{
	char	**temp;
	int		i;
	int		j;

	temp = argv;
	j = -1;
	while (argv[++j])
	{
		i = -1;
		while (temp[++i])
		{
			if (i == j)
				continue ;
			if (ft_atoi(argv[j]) == ft_atoi(temp[i]))
				return (1);
		}
	}
	return (0);
}

int	check_sign(char **numbers)
{
	int		i;
	int		j;
	char	**temp;
	int		sign;

	sign = 0;
	temp = numbers;
	i = -1;
	while (temp[++i])
	{
		if ((temp[i][0] == '+' || temp[i][0] == '-') && (temp[i][1] != 0
				&& (temp[i][1] < '0' || temp[i][1] > '9')))
			return (0);
	}
	return (1);
}
