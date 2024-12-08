/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:39:54 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 22:16:16 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "./libft/headers/libft.h"

typedef struct s_node
{
	int				data;
	int				cost;
	int				index;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				ft_sort_small(t_stack *a, t_stack *b);
void				ft_sort_three(t_stack *stacka);
void				ft_get_indexes(t_stack *stack);
t_node				*ft_get_max(t_stack *stack);
t_node				*ft_get_min(t_stack *stack);
int					ft_checksorted(t_stack *stack);
void				ft_free_stack(t_stack *stack);
void				ft_free_both(t_stack *stacka, t_stack *stackb);
void				ft_print_stack(t_stack *stack);
void				ft_fill_stack(t_stack *stack, int argc, char *argv[],
						int c);
t_stack				*ft_init_stack(void);
void				ft_push(t_stack *stack_x, t_stack *stack_y);
void				ft_swap(t_stack *stack);
void				ft_rotate(t_stack *stack);
void				ft_reverse_rotate(t_stack *stack);
void				ft_ss(t_stack *stack_x, t_stack *stack_y, t_node *tmp_a,
						t_node *tmp_b);
void				ft_rr(t_stack *stacka, t_stack *stackb, t_node *tmp_a,
						t_node *tmp_b);
void				ft_rrr(t_stack *stacka, t_stack *stackb, t_node *tmp_a,
						t_node *tmp_b);
void				ft_ra(t_stack *a, int *count);
void				ft_rra(t_stack *a, int *count);
void				ft_pa(t_stack *a, t_stack *b);
void				ft_sb(t_stack *b, int *count);
void				ft_ras(t_stack *a);
void				ft_rras(t_stack *a);
void				ft_sas(t_stack *a);
void				ft_sbs(t_stack *b);
void				ft_pb(t_stack *a, t_stack *b);
void				ft_sa(t_stack *a, int *count);
void				ft_rb(t_stack *b, int *count);
void				ft_rrb(t_stack *b, int *count);
void				ft_error(void);
t_node				*ft_lastnode(t_node *lst);
t_node				*ft_before_lastnode(t_node *lst);
void				ft_nodeadd_back(t_stack *stack, t_node *newnode);
void				ft_nodeadd_front(t_stack *stack, t_node *newnode);
int					ft_check_fill(t_stack *stack, int argc, char **argv, int c);
void				ft_sort_large(t_stack *a, t_stack *b);
int					ft_direction(int tmp, t_stack *stack_a);
void				ft_same_direction(t_stack *a, t_stack *b, t_node *tmp_a,
						t_node *tmp_b);
t_node				*ft_least_cost(t_stack *a, t_stack *b);
void				ft_calculate_costs(t_stack *a, t_stack *b);
int					ft_cost(t_stack *a, t_stack *b, t_node *na, t_node *nb);
t_node				*ft_find_target(t_stack *stack, t_node *node);
void				ft_different_direction(t_stack *a, t_stack *b,
						t_node *tmp_a, t_node *tmp_b);
void				ft_do_the_operations(t_stack *a, t_stack *b, t_node *tmp_a,
						t_node *tmp_b);
void				ft_sort(t_stack *a, t_stack *b);
int					get_position(t_stack *stack, t_node *node);
#endif
