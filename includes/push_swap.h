/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:26:17 by zlee              #+#    #+#             */
/*   Updated: 2025/03/05 09:23:57 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

enum			e_stk
{
	STK_A,
	STK_B
};

typedef struct s_d
{
	int			index;
	int			num;
	enum e_stk	loc;
	int			pre_sort;
	t_list		*moves;
}				t_d;

/*Sorting*/
void			s_stack(t_list **stacks);
void			p_stack(t_list **stack_a, t_list **stack_b);
void			r_stack(t_list **stacks);
void			rr_stack(t_list **stacks);
/*Make above sorting into one function for simplicity*/
void			r_rr_bot(t_list **s1, t_list **s2, t_list *node, int partition);
void			r_rr_top(t_list **s1, t_list **s2, t_list *node, int partition);
/*parsing*/
int				num_check(char *string);
int				error_msg(void);
void			free_numbers(char **arr);
int				input_check(int argc, char **argv);
int				check_dup(char **argv);
int				get_number_node(t_list *s);
int				get_index(t_list *s);
int				get_p(t_list *s);
void			free_tdata(t_d *data);
/*Simple sort for partitions*/
void			sort_two(t_list **s_a);
void			sort_two_inv(t_list **s_a);
void			sort_two_three(t_list **s_a);
void			sort_three(t_list **s_a);
/*data prepping*/
void			reindex_stack(t_list **stack_a, t_list **stack_b);
void			ft_swap(t_list **s1, t_list **s2);
void			deter_rotate_stk(t_list **stk, t_list *target_n);
void			r_stk(t_list **stk, t_list *target_n);
void			rr_stk(t_list **stk, t_list *target_n);
/*checking*/
int				is_sorted(t_list *s);
void			change_location(t_list **stack, enum e_stk loc);
enum e_stk		get_location(t_list *stack);
int				get_par(t_list *stack);
/*Turk Sort Functions*/
void			print_each_partition(t_list *stacks);
t_d				*prep_data(int index, int numbers);
char			**ft_split_extended(int argc, char **argv);
/*Turk*/
/*Sorting*/
void			push_swap(char **numbers);
void			pre_sort(t_list **stack);
void			set_presort_number(t_list **stack, t_list *node, int number);
int				get_presort_num(t_list *stack);
void			print_presort(t_list *sa);
void			split_push(t_list **sa, t_list **sb);
void			turk_sort(t_list **sa, t_list **sb);
void			determine_turk_sort(t_list **sa, t_list **sb);
void			execute_push(t_list **sa, t_list **sb, t_list *node);
void			node_execution(t_list **sa, t_list **sb, t_list *inst);
void			node_execution_two(t_list **sa, t_list **sb, t_list *inst);
int				find_middle(t_list *sa, t_list *node, t_list **dst2);
t_list			*find_small(t_list *stack);
t_list			*find_large(t_list *stack);
void			free_moves(t_list **stack);
t_list			*find_cheapest(t_list *stack);
void			r_all(t_list **stack, t_list *head);
void			rr_all(t_list **stack, t_list *head);
/*Instructions*/
void			ra_instructions(t_list **sb, t_list *target);
void			rra_instructions(t_list *sa, t_list **sb, t_list *target);
void			rb_instructions(t_list **sb, t_list *node);
void			rrb_instructions(t_list *stack, t_list **sb, t_list *node);
/**/
void			determine_rotate_mid_small(t_list *sa, t_list **sb,
					t_list *target, t_list *node);
void			determine_rotate_large(t_list *sa, t_list **sb, t_list *target,
					t_list *node);
int				check_sign(char **numbers);
/*Printing (for debug only)*/
void			print_each_instructions(t_list *stack);
#endif
