/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:51 by zlee              #+#    #+#             */
/*   Updated: 2025/03/07 10:46:34 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*If 0: Add instructions, if 1, print instructions, 2, free instructions*/
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
		instructions = NULL;
	}	
	else if (print == 2)
		ft_lstclear(&instructions, free);
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
