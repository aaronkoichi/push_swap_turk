/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_numbers_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:09:12 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 15:32:32 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	num_check(char *string)
{
	int	in_words;
	int	word_count;

	in_words = 0;
	word_count = 0;
	while (*string != 0)
	{
		if (in_words && (*string == '-' || *string == '+'))
			return (-1);
		if ((*string == '-' || *string == '+' || (*string >= '0'
					&& *string <= '9')) && !in_words)
		{
			in_words = 1;
			word_count++;
		}
		else if (*string == ' ' && in_words)
			in_words = 0;
		if ((*string < '0' || *string > '9') && *string != ' ' && *string != '-'
			&& *string != '+')
			return (-1);
		string++;
	}
	return (word_count);
}

int	error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

void	free_numbers(char **arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i++])
		count++;
	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
}

int	input_check(int argc, char **argv)
{
	int	i;
	int	count;
	int	temp;

	count = 0;
	i = 0;
	if (argc < 2)
		return (error_msg());
	if (argc == 2)
		count = num_check(argv[argc - 1]);
	else if (argc > 2)
	{
		while (++i < argc)
		{
			temp = num_check(argv[i]);
			if (temp == -1)
				return (error_msg());
			count += temp;
		}
	}
	if (count == -1)
		return (error_msg());
	return (count);
}

char	**ft_split_extended(int argc, char **argv)
{
	char	*temp;
	char	*numbers;
	char	**splitted;
	int		i;

	temp = NULL;
	numbers = ft_strdup("");
	i = 0;
	while (++i < argc)
	{
		temp = ft_strjoin(numbers, argv[i]);
		free(numbers);
		numbers = temp;
		temp = ft_strjoin(numbers, " ");
		free(numbers);
		numbers = temp;
	}
	splitted = ft_split(numbers, ' ');
	free(numbers);
	return (splitted);
}
