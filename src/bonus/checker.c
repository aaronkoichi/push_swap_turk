/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:37:21 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:38:01 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"
#include "../../includes/push_swap.h"

void	ps_checker(char **n)
{
	t_list	*s_a;
	t_list	*s_b;
	int		i;

	i = -1;
	s_a = NULL;
	s_b = NULL;
	while (n[++i])
		ft_lstadd_back(&s_a, ft_lstnew(prep_data(i, ft_atoi(n[i]))));
	pre_sort(&s_a);
	process_instructions(&s_a, &s_b);
	ft_lstclear(&s_a, free);
	ft_lstclear(&s_b, free);
}

int	check_commands(char *inst)
{
	if (!inst)
		return (0);
	if (ft_strncmp(inst, "sa\n", 3) == 0 || ft_strncmp(inst, "sb\n", 3) == 0
		|| ft_strncmp(inst, "ss\n", 3) == 0 || ft_strncmp(inst, "ra\n", 3) == 0
		|| ft_strncmp(inst, "rb\n", 3) == 0 || ft_strncmp(inst, "rr\n", 3) == 0
		|| ft_strncmp(inst, "rra\n", 4) == 0 || ft_strncmp(inst, "rrb\n", 4) == 0
		|| ft_strncmp(inst, "rrr\n", 4) == 0 || ft_strncmp(inst, "pa\n", 3) == 0
		|| ft_strncmp(inst, "pb\n", 3) == 0)
		return (1);
	return (0);
}

int	prompt_inst(char **string, t_list **instructions)
{
	int	checker;

	checker = 1;
	*string = get_next_line(0);
	while (*string)
	{
		if (!check_commands(*string))
		{
			checker = 0;
			error_msg();
			free(*string);
			*string = NULL;
			break ;
		}
		ft_lstadd_back(instructions, ft_lstnew(*string));
		*string = get_next_line(0);
	}
	return (checker);
}

void	process_instructions(t_list **sa, t_list **sb)
{
	char	*string;
	t_list	*instructions;
	int		checker;

	instructions = NULL;
	string = NULL;
	checker = prompt_inst(&string, &instructions);
	if (string)
		free(string);
	if (!checker)
	{
		if (instructions)
			ft_lstclear(&instructions, free);
		return ;
	}
	execute_push(sa, sb, instructions);
	ft_lstclear(&instructions, free);
	if (!is_sorted(*sa) || *sb)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	store_instructions(NULL, 2);
}
