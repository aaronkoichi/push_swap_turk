/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:51 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 16:48:55 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	store_instructions(char *instruction, int print)
{
	static t_list	*instructions;

	if (!instructions)
		instructions = NULL;
	if (print == 1)
	{
		optimize_instructions(&instructions);
		print_instructions(instructions);
		ft_lstclear(&instructions, free);
		instructions =  NULL;
	}	
	else		
		ft_lstadd_back(&instructions, ft_lstnew(ft_strdup(instruction)));
}

void	print_instructions(t_list *instructions)
{
	while (instructions)
	{
		ft_printf("%s", (char *)instructions->content);
		instructions = instructions->next;
	}
}