/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:39:54 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/03 09:04:59 by eaqrabaw         ###   ########.fr       */
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
    int             index;
    int             cost;
	struct s_node	*next;

}					t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}    t_stack;
//------------------------Sorting Small--------------------------------------------------
void                ft_sort_small(t_stack *a, t_stack *b);
void                ft_sort_three(t_stack *stacka);
void                ft_get_indexes(t_stack *stack);
t_node              *ft_get_max(t_stack *stack);
t_node              *ft_get_min(t_stack *stack);
int                 ft_checksorted(t_stack *stack);
//-----------------------stack--------------------------------------------------------------
void				ft_free_stack(t_stack *stack);
void 	            ft_free_both(t_stack *stacka, t_stack *stackb);
void				ft_print_stack(t_stack *stack);
void				ft_fill_stack(t_stack *stack, int argc, char *argv[],int c);
t_stack				*ft_init_stack(void);
//--------------------basic Operations -------------------------------------------------------------
void				ft_push(t_stack *stack_x, t_stack *stack_y);
void				ft_swap(t_stack *stack);
void				ft_rotate(t_stack *stack);
void				ft_reverse_rotate(t_stack *stack);
//--------------------Stack A & B operations----------------------------------------------------
void				ft_ss(t_stack *stack_x, t_stack *stack_y);
void				ft_rr(t_stack *stacka, t_stack *stackb);
void				ft_rrr(t_stack *stacka, t_stack *stackb);
//-------------------Stack A operations--------------------------------------------------------
void                ft_ra(t_stack *a);
void                ft_rra(t_stack *a);
void                ft_pa(t_stack *a, t_stack *b);
void                ft_sb(t_stack *b);
//-------------------Stack B Operations--------------------------------------------------------
void                ft_pb(t_stack *a, t_stack *b);
void                ft_sa(t_stack *a);
void                ft_rb(t_stack *b);
void                ft_rrb(t_stack *b);
//----------------------Error ------------------------------------------------------------
void				ft_error(void);
//-----------------------------Nodes ops---------------------------------------------------
t_node				*ft_lastnode(t_node *lst);
t_node				*ft_before_lastnode(t_node *lst);
void				ft_nodeadd_back(t_stack *stack, t_node *newnode);
void				ft_nodeadd_front(t_stack *stack, t_node *newnode);
int		            ft_check_fill(t_stack *stack, int argc, char **argv, int c);
//--------------------Sorting Large----------------------------------------------------------------
void                ft_sort_large(t_stack *a, t_stack *b);
void                ft_calculate_cost(t_stack *a, t_stack *b);
t_node              *ft_get_least_cost(t_stack *a);
#endif