/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:26:17 by zlee              #+#    #+#             */
/*   Updated: 2025/02/28 21:26:37 by zlee             ###   ########.fr       */
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

enum	e_stk
{
	A,
	B
};

typedef struct s_par_loc
{
	enum e_loc	loc;
	int			par;
	int			mul;
}				t_par_loc;

typedef struct s_d
{
	int			index;
	int			num;
	enum e_loc	location;
	int			p_num;
	int			pre_sort;
}				t_d;

typedef struct s_pivots
{
	t_list		*p1;
	t_list		*p2;
}				t_pivots;

typedef struct s_info
{
	t_list		*n_ts;
	int			multiplier;
}				t_info;

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
int				get_par_frm_loc(t_list *stacks, enum e_loc loc);
void			push_back(t_list **s1, t_list **s2, enum e_loc loc,
					int partition);
void			push_to_a(t_list **s1, t_list **s2, enum e_loc loc, int par);
void			push_to_b(t_list **s1, t_list **s2, enum e_loc loc, int par);
void			determine_new_loc_par_a(t_list **s1, enum e_loc *new_loc,
					int *new_par, int par);
void			prepare_stack_a(t_list **s1);
void			position_stack_b(t_list **s2, enum e_loc loc, int par);
void			execute_push_to_a(t_list **s1, t_list **s2, enum e_loc new_loc,
					int new_par);
void			determine_new_loc_par_b(t_list **s2, enum e_loc *new_loc,
					int *new_par, int par);
void			prepare_stack_b(t_list **s1);
void			position_stack_a(t_list **s1, enum e_loc loc, int par);
void			execute_push_to_b(t_list **s1, t_list **s2, enum e_loc new_loc,
					int new_par);
/*parsing*/
int				num_check(char *string);
int				error_msg(void);
void			free_numbers(char **arr);
int				input_check(int argc, char **argv);
char			**ft_split_extended(int argc, char **argv);
int				check_dup(char **argv);
int				get_number_node(t_list *s);
int				get_index(t_list *s);
t_list			*get_node_index_par(t_list *stack, int index, enum e_loc loc,
					int par);
int				get_p(t_list *s);
void			free_tdata(t_d *data);
/*Sorting*/
void			push_swap(char **numbers);
void			find_two_pivot_a(t_list **stk, t_pivots *p, enum e_loc loc,
					int p_num);
void			find_two_pivot_b(t_list **stk, t_pivots *p, enum e_loc loc,
					int p_num);
void			do_swap_a(t_list **s_a, t_list **s_b, int p_size,
					enum e_loc loc);
void			do_swap_b(t_list **s_a, t_list **s_b, int p_num,
					enum e_loc loc);
void			do_swap_checker(t_list **s1, t_list **s2, int p_num,
					enum e_loc loc);
void			create_chunk_a(t_list **s1, t_list **s2, t_pivots pvts,
					t_par_loc plm);
void			create_chunk_b(t_list **s1, t_list **s2, t_pivots pvts,
					t_par_loc plm);
void			prc_chunk_to_a(t_list **s1, t_list **s2, t_pivots pivots,
					t_info info);
void			prc_chunk_to_b(t_list **s1, t_list **s2, t_pivots pivots,
					t_info info);
void			pre_sort(t_list **stack, enum e_loc loc, int partition);
void			set_presort_number(t_list **stack, t_list *node, int number);
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
t_d				*prep_data(int ind, int num, enum e_loc location, int p);
t_d				*dup_data(t_d *content);
void			change_location(t_list **stack, enum e_loc loc);
void			change_location_lst(t_list **s, enum e_loc new,
					enum e_loc exist, int p);
void			change_par(t_list **stack, int num);
void			change_par_list(t_list **stack, int num);
void			reindex_stack(t_list **stack_a, t_list **stack_b);
void			ft_swap(t_list **s1, t_list **s2);
t_list			*find_last_node_chunk(t_list *stk, enum e_loc loc, int p_num);
void			deter_rotate_stk(t_list **stk, t_list *target_n);
void			r_stk(t_list **stk, t_list *target_n);
void			rr_stk(t_list **stk, t_list *target_n);
/*checking*/
int				is_sorted(t_list *s);
t_list			*get_first_node_par(t_list *s, enum e_loc loc, int p_num);
int				srtd_chk(t_list *s, enum e_loc loc, int p_num);
int				srtd_chk_inv(t_list *s, enum e_loc loc, int p_num);
int				check_node_sorted(t_list *s);
void			print_both_stacks(t_list *s_a, t_list *s_b);
enum e_loc		get_location(t_list *stack);
int				get_par(t_list *stack);
/*Turk Sort Functions*/
t_list			*get_small_node(t_list *s1, int p_num, enum e_loc loc);
t_list			*get_large_node(t_list *s1, int p_num, enum e_loc loc);
int				check_par_loc(t_list *s1, int p_num, enum e_loc loc);
t_list			*get_loc_par_node(t_list *s1, int p_num, enum e_loc loc);
void			print_each_partition(t_list *stacks);
t_par_loc		find_next_partition(t_list *s1, enum e_loc location);
t_par_loc		deter_next_partition_top(t_list *s1, t_list *s2);
t_par_loc		deter_next_partition_bot(t_list *s1, t_list *s2);
t_par_loc		next_large_partition(t_list *s1, t_list *s2);
int				count_size_par(t_list *stack, int partition,
					enum e_loc location);
void			recurse_do_swap(t_list **s_a, t_list **s_b, int p,
					enum e_loc loc);
#endif
