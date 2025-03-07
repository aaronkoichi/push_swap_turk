/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_numbers_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:09:12 by zlee              #+#    #+#             */
/*   Updated: 2025/03/08 03:02:02 by zlee             ###   ########.fr       */
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

static int	count_ws(const char *nptr)
{
	int	index;

	index = 0;
	while (nptr[index] == 32 || (nptr[index] >= 9 && nptr[index] <= 13))
		index++;
	return (index);
}

long	ft_atol(const char *nptr)
{
	long	multiple;
	long	index;
	long	total;

	multiple = 1;
	total = 0;
	index = count_ws(nptr);
	if (nptr[index] == '-' || nptr[index] == '+')
		if (nptr[index++] == '-')
			multiple = -1;
	while (nptr[index] >= '0' && nptr[index] <= '9')
		total = (total * 10) + (nptr[index++] - 48);
	return (total * multiple);
}

int	check_long(char **numbers)
{
	int	i;

	i = -1;
	while (numbers[++i])
	{
		if (ft_strlen(numbers[0]) >= 12)
			return (0);
		if (ft_strlen(numbers[0]) == 1 && (numbers[0][0] == '+'
			|| numbers[0][0] == '-'))
			return (0);
		if (ft_atol(numbers[0]) > INT_MAX || ft_atol(numbers[0]) < INT_MIN)
			return (0);
	}
	return (1);
}
