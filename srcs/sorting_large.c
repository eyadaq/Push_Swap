/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 07:16:13 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_sortb_descending(t_stack *b)
{
    t_node      *min;
    t_node      *max;

    max = ft_get_max(b);
    min = ft_get_min(b);

    if (ft_direction(max->index, b))
        max->cost = (1 + b->size - max->index);
    else 
        max->cost = max->index - 1;
    if (ft_direction(min->index, b))
        min->cost = (b->size - min->index);
    else 
        min->cost = (min->index);
    if (min->cost < max->cost && ft_direction(min->index, b))
        ft_rrb(b,&min->cost);    
    else if (min->cost < max->cost)
        ft_rb(b,&min->cost);
    else if (min->cost > max->cost && ft_direction(max->index, b))
        ft_rrb(b,&max->cost);
    else if (ft_direction(max->index, b))
        ft_rrb(b,&max->cost);
    else 
        ft_rb(b, &min->cost);
    return ;    
}

void ft_final_sort(t_stack *a, t_stack *b) {

    t_node *a_last = a->top;
    t_node *b_head = b->top;
    int i = 3;

    while (a_last->next)
        a_last = a_last->next;
    while (b->size > 0 && b_head)
     {
        while (i > 0 && b_head && a_last && b_head->data < a_last->data) 
        {
            a_last = a_last->prev;
            ft_rras(a);
            i--;
        }
        ft_pa(a, b);
        b_head =b->top;
    }
    if (i > 0)
        while (i > 0)
        {
           ft_rras(a);
           i--; 
        }
}

void        ft_sort_largee(t_stack *a, t_stack *b)
{
    t_node *least_cost_node;
    
    ft_pb(a, b);
    ft_pb(a, b);
    if (b->top->data < b->top->next->data)
        ft_sbs(b);
     while (a->size > 3)
    {
        least_cost_node = ft_least_cost(a, b);
        if (least_cost_node->index == 1 && least_cost_node->target->index == 1)
            ft_pb(a,b);
        else
        {
            ft_do_the_operations(a,b,least_cost_node , least_cost_node->target);
            ft_pb(a,b);
        }
    }
    ft_sort_three(a);
    ft_get_indexes(b);
    ft_print_stack(a);
    ft_printf("---------------Stack A before the last sort\n");
    ft_sortb_descending(b);
    ft_get_indexes(b);
    ft_final_sort(a, b);
}
