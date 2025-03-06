/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:50:41 by zlee              #+#    #+#             */
/*   Updated: 2025/03/06 16:47:36 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	compare_rotate(char *content)
{
	if (!ft_strncmp(content, "ra\n", 2) || !ft_strncmp(content, "rb\n", 2)
		|| !ft_strncmp(content, "rra\n", 3) || !ft_strncmp(content, "rrb\n", 3))
		return (0);
	else
		return (1);
}

void	optimize_instructions(t_list **inst)
{
	t_list	*checkpoint;
	t_list	*new_list;
	t_list	*head;
	int		rolling_a;
	int		rolling_b;

	rolling_a = 0;
	rolling_b = 0;
	checkpoint = NULL;
	new_list = NULL;
	head = *inst;
	while (head)
	{
		if (!compare_rotate((head)->content))
		{
			checkpoint = head;
			while (head && !compare_rotate((head)->content))
				(head) = (head)->next;
			trim_inst(checkpoint, &rolling_a, &rolling_b);
			assign_inst_rr_rrr(&new_list, &rolling_a, &rolling_b);
		}
		else
		{
			ft_lstadd_back(&new_list, ft_lstnew(ft_strdup((head)->content)));
			(head) = (head)->next;
		}
	}
	ft_lstclear(inst, free);
	*inst = new_list;
}

void	assign_inst_rr_rrr(t_list **checkpoint, int *rolling_a, int *rolling_b)
{
	while (*rolling_a > 0 && *rolling_b > 0)
	{
		ft_lstadd_back(checkpoint, ft_lstnew(ft_strdup("rr\n")));
		(*rolling_a)--;
		(*rolling_b)--;
	}
	while (*rolling_a < 0 && *rolling_b < 0)
	{
		ft_lstadd_back(checkpoint, ft_lstnew(ft_strdup("rrr\n")));
		(*rolling_a)++;
		(*rolling_b)++;
	}
	assign_inst_individual(checkpoint, rolling_a, rolling_b);
}

void	assign_inst_individual(t_list **inst, int *rolling_a, int *rolling_b)
{
	while (*rolling_a > 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("ra\n")));
		(*rolling_a)--;
	}
	while (*rolling_a < 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rra\n")));
		(*rolling_a)++;
	}
	while (*rolling_b > 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rb\n")));
		(*rolling_b)--;
	}
	while (*rolling_b < 0)
	{
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rrb\n")));
		(*rolling_b)++;
	}
}

void	trim_inst(t_list *inst, int *rolling_a, int *rolling_b)
{
	while (inst && (!compare_rotate(inst->content)))
	{
		if (!ft_strncmp(inst->content, "ra\n", 3))
			(*rolling_a)++;
		else if (!ft_strncmp(inst->content, "rb\n", 3))
			(*rolling_b)++;
		else if (!ft_strncmp(inst->content, "rra\n", 4))
			(*rolling_a)--;
		else if (!ft_strncmp(inst->content, "rrb\n", 4))
			(*rolling_b)--;
		inst = inst->next;
	}
}

// int	main(void)
// {
// 	t_list	*test;
// 	t_list	*head;

// 	test = NULL;
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("ra\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("pb\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("pb\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("ra\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("ra\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("rb\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("rb\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("rra\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("rrb\n")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("pb\n")));
// 	head = test;
// 	ft_printf("Instructions: ");
// 	while (test)
// 	{
// 		ft_printf("%s, ", (char *)test->content);
// 		test = test->next;
// 	}
// 	ft_printf("\n");
// 	test = head;
// 	optimize_instructions(&test);
// 	ft_printf("Optimized: ");
// 	while (test)
// 	{
// 		ft_printf("%s, ", (char *)test->content);
// 		test = test->next;
// 	}
// 	ft_printf("\n");
// 	test = head;
// 	//ft_lstclear(&test, free);
// }
