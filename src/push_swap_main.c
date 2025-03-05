/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:33:34 by zlee              #+#    #+#             */
/*   Updated: 2025/03/05 09:31:06 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		checker;
	char	**numbers;

	checker = 0;
	if (argc == 1)
		return (0);
	checker = input_check(argc, argv);
	if (checker == -1)
		return (0);
	else
	{
		numbers = ft_split_extended(argc, argv);
		if (check_dup(numbers) || !check_sign(numbers))
		{
			free_numbers(numbers);
			return (error_msg());
		}
		push_swap(numbers);
		free_numbers(numbers);
	}
}
