/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:09:01 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/02 00:08:12 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node    *ft_leastnodecost(t_stack *a, t_stack *b)
{
    t_node      *node;
    t_node      *least;
    
    ft_calc_cost(a,b);
    least = a->top;
    node = least->next;
    while (node)
    {
        if (node->cost < least->cost)
            least = node;
        node = node->next;
    }
    return (least);
}

static void    ft_move_a(t_stack *a, t_node *node, int move)
{
    int     counter;

    counter = 0;
    if (1 == move)
    {
        while (counter < (node->cost - 1))
        {
            ft_ra(a);
            counter++;
        }
        return ;
    }
    if (2 == move)
    {
        while (counter < (node->cost - 1))
        {
            ft_rra(a);
            counter++;
        }
        return ;        
    }
}

static void    ft_move_b(t_stack *b, t_node *node, int move)
{
    int     counter;

    counter = 0;
    if (1 == move)
    {
        while (counter < (node->cost))
        {
            ft_rb(b);
            counter++;
        }
        return ;
    }
    if (2 == move)
    {
        while (counter < (node->cost - 3))
        {
            ft_rrb(b);
            counter++;
        }
        return ;        
    }
}

static void     ft_push_least_cost(t_stack *a, t_stack *b)
{
    t_node      *node;
    t_node      *max;
    t_node      *min;
    int     bcost;
    
    min = ft_get_min(b);
    max = ft_get_max(b);
    node = ft_leastnodecost(a, b);
    bcost = ft_calc_bcost(b, node);
    if (node->data > max->data)
    {
        ft_pb(a,b);
        return ;
    }
    if (node->data < min->data)
    {
        ft_pb(a,b);
        ft_rb(b);
        return ;
    }
    if (node->index <= (a->size / 2))
        ft_move_a(a,node,1);   
    else if (node->index > (a->size / 2))
        ft_move_a(a, node ,2);   
    if (bcost > 0 && bcost <= (b->size / 2))
        ft_move_b(b, node ,1);
    else if (bcost > 0 && bcost > (b->size / 2))
        ft_move_b(b, node ,2);
    ft_pb(a,b);
    return ;
}

void        ft_sort_large(t_stack *a, t_stack *b)
{
    ft_pb(a,b);
    ft_pb(a,b);
    make_it_top(b);
    while (3 < a->size)
    {
        ft_push_least_cost(a,b);
        make_it_top(b);
    }
    make_it_top(b);
    if (3 == a->size)
        ft_sort_three(a);
       
}