/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 00:10:06 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     ft_direction(int tmp, t_stack *stack_a)
{
    if (tmp > (stack_a->size / 2))
        return (1);
    else
        return (0);
}


void    ft_same_direction(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b)
{
    if (ft_direction(tmp_a->index, a))
    {
        tmp_a->cost = a->size - tmp_a->index + 1;
        tmp_b->cost = b->size - tmp_b->index + 1;
        ft_rrr(a, b, tmp_a, tmp_b);
        ft_rra(a, &tmp_a->cost);
        ft_rrb(b, &tmp_b->cost);
    }
    else
    {
        tmp_a->cost = tmp_a->index - 1;
        tmp_b->cost = tmp_b->index - 1;
        ft_rr(a, b, tmp_a, tmp_b);
        if (tmp_a->index != 1)
            ft_ra(a, &tmp_a->cost);
        if (tmp_b->index != 1)
            ft_rb(b, &tmp_b->cost);
    }
}

void    ft_different_direction(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b)
{
    if (ft_direction(tmp_a->index, a))
    {
        tmp_a->cost = (1 +  a->size - tmp_a->index);
        ft_rra(a, &tmp_a->cost);
    }
    else
    {
        tmp_a->cost = (tmp_a->index - 1);
        ft_ra(a, &tmp_a->cost);
    }

    if (ft_direction(tmp_b->index, b))
    {
        tmp_b->cost = 1 + b->size - tmp_b->index;
        ft_rrb(b, &tmp_b->cost);
    }
    else 
    {   
        tmp_b->cost = tmp_b->index - 1;
        if (tmp_b->index != 1)
            ft_rb(b, &tmp_b->cost);
    }
}
void    ft_do_the_operations(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b)
{
    int index_a = tmp_a->index;
    int index_b = tmp_b->index;

    if (ft_direction(index_a, a) == ft_direction(index_b, b))
    {
        ft_same_direction(a, b, tmp_a, tmp_b);
    }
    else
    {
        ft_different_direction(a, b, tmp_a, tmp_b);
    }
}


t_node      *ft_find_target(t_stack *stack, t_node *node)
{
    t_node *target; 
    t_node *current;

    if (!stack || !node || !stack->top)
        return NULL;

    current = stack->top;
    target = NULL;
    while (current)
    {
        if (current->data < node->data)
        {
            if (!target || current->data > target->data)
            {
                target = current;
            }
        }
        current = current->next;
    }
    if (!target)
        target = ft_get_max(stack);
    return target;
}

int     ft_cost(t_stack *a, t_stack *b, t_node *na, t_node *nb)
{
    int     cost;

    cost = 0;
    if (ft_direction(na->index, a) == ft_direction(nb->index,b))
    {
        if (ft_direction(na->index, a))
        {
            if ((a->size - na->index) > (b->size - nb->index))
                cost = a->size - na->index;
            else
                cost = b->size - nb->index;;
        }
        else
        {
            if (na->index > nb->index)
                cost = na->index - 1;
            else
                cost = nb->index;
        }
        return (cost);
    }
    if (ft_direction(na->index,a))
        cost = a->size - na->index;
    else
        cost = na->index;
    if (ft_direction(nb->index, b))
        cost += b->size - nb->index;
    else
        cost += nb->index;
    return (cost);
}

void    ft_calculate_costs(t_stack *a, t_stack *b)
{
    t_node   *sa;

    sa = a->top;
    while (sa)
    {
        sa->target = ft_find_target(b, sa);
        sa->cost = ft_cost(a,b,sa,sa->target);
        sa = sa->next;
    }
    return ;
}

t_node      *ft_least_cost(t_stack *a, t_stack *b)
{
    t_node  *node;
    t_node  *least;
    
    ft_get_indexes(a);
    ft_get_indexes(b);
    ft_calculate_costs(a,b);
    node = a->top;
    least = node;
    while (node)
    {
        if (node->cost < least->cost)
            least = node;
        node = node->next;
    }
    return (least);
}

void    ft_sortb_descending(t_stack *b)
{
    t_node      *min;
    t_node      *max;

    max = ft_get_max(b);
    min = ft_get_min(b);

    if (ft_direction(max->index, b))
        max->cost =  1 + b->size - max->index;
    else 
        max->cost = max->index - 1;
    if (ft_direction(min->index, b))
        min->cost = b->size - min->index;
    else 
        min->cost = (min->index);
    if (min->cost < max->cost && ft_direction(min->index, b))
        ft_rrb(b,&min->cost);    
    else if (min->cost < max->cost)
        ft_rb(b,&min->cost);
    else if (min->cost > max->cost && ft_direction(max->index, b))
        ft_rrb(b,&max->cost);
    else
        ft_rb(b,&max->cost);
    return ;    
}

void ft_final_sort(t_stack *a, t_stack *b) {

    t_node *a_last = a->top;
    t_node *b_head = b->top;
    int i = 3;

    while (a_last->next) {
        a_last = a_last->next;
    }    
    while (b->size > 0 && b_head) {
        while (i > 0 && b_head && a_last && b_head->data < a_last->data) {
            a_last = a_last->prev;
            ft_rras(a);
            i--;
        }
        ft_pa(a, b);
        b_head =b->top;
    }
}

void        ft_sort_largee(t_stack *a, t_stack *b)
{
    ft_pb(a, b);
    ft_pb(a, b);
    if (b->top->data < b->top->next->data)
        ft_sbs(b);
     while (a->size > 3)
    {
        t_node *least_cost_node = ft_least_cost(a, b);
        if (least_cost_node->index == 1 && least_cost_node->target->index == 1)
            ft_pb(a,b);
        else {
            ft_do_the_operations(a,b,least_cost_node , least_cost_node->target );
            ft_pb(a,b);
        }
    }
    ft_sort_three(a);
    ft_get_indexes(b);
    ft_sortb_descending(b);
    ft_final_sort(a, b);
}
