/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:26:17 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 23:06:46 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

enum			e_loc
{
	MID_A,
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B,
	SORTED,
};

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
}				t_d;

/*Sorting*/
void			s_stack(t_list **stacks);
void			p_stack(t_list **stack_a, t_list **stack_b);
void			r_stack(t_list **stacks);
void			rr_stack(t_list **stacks);
/*Advanced sorting --> a to b*/
void			ra_pb_top(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
void			rra_pb_top(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
void			ra_pb_bot(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
void			rra_pb_bot(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
/*b to a*/
void			rb_pa_top(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
void			rrb_pa_top(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
void			rb_pa_bot(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
void			rrb_pa_bot(t_list **s_a, t_list **s_b, t_list *node,
					int partition);
/*Make above sorting into one function for simplicity*/
void			r_rr_bot(t_list **s1, t_list **s2, t_list *node, int partition);
void			r_rr_top(t_list **s1, t_list **s2, t_list *node, int partition);
/*push back functions*/
int				find_location(t_list *stacks, enum e_loc loc);
/*parsing*/
int				num_check(char *string);
int				error_msg(void);
void			free_numbers(char **arr);
int				input_check(int argc, char **argv);
int				check_dup(char **argv);
int				get_number_node(t_list *s);
int				get_index(t_list *s);
t_list			*get_node_index_par(t_list *stack, int index, enum e_loc loc,
					int par);
int				get_p(t_list *s);
void			free_tdata(t_d *data);
/*Simple sort for partitions*/
void			sort_two_a(t_list **stack, int p_num, enum e_loc location);
void			sort_two_b(t_list **stack, int p_num, enum e_loc location);
void			sort_three_a(t_list **s1, t_list **s2, int p_num,
					enum e_loc location);
void			sort_three_b(t_list **s1, t_list **s2, int p_num,
					enum e_loc location);
void			sort_three_partition(t_list **s1, t_list **s2, int p,
					enum e_loc loc);
void			sort_two(t_list **s_a);
void			sort_two_inv(t_list **s_a);
void			sort_two_three(t_list **s_a);
void			sort_three(t_list **s_a);
/*data prepping*/
void			change_location(t_list **stack, enum e_stk loc);
void			reindex_stack(t_list **stack_a, t_list **stack_b);
void			ft_swap(t_list **s1, t_list **s2);
void			deter_rotate_stk(t_list **stk, t_list *target_n);
void			r_stk(t_list **stk, t_list *target_n);
void			rr_stk(t_list **stk, t_list *target_n);
/*checking*/
int				is_sorted(t_list *s);
enum e_stk		get_location(t_list *stack);
int				get_par(t_list *stack);
/*Turk Sort Functions*/
void			print_each_partition(t_list *stacks);
t_d				*prep_data(int index, int numbers, enum e_stk loc);
char			**ft_split_extended(int argc, char **argv);
/*Turk*/
/*Sorting*/
void			push_swap(char **numbers);
void			pre_sort(t_list **stack);
void			set_presort_number(t_list **stack, t_list *node, int number);
int				get_presort_num(t_list *stack);
void			print_presort(t_list *sa);
#endif
