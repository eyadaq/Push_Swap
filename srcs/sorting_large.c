/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/07 00:09:30 by eaqrabaw         ###   ########.fr       */
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
        tmp_a->cost = a->size - tmp_a->index;
        tmp_b->cost = b->size - tmp_b->index;
        ft_rrr(a, b, tmp_a, tmp_b);
        ft_rra(a, &tmp_a->cost);
        ft_rrb(b, &tmp_b->cost);
    }
    else
    {
        ft_rr(a, b, tmp_a, tmp_b);
        ft_ra(a, &tmp_a->cost);
        ft_rb(b, &tmp_b->cost);
    }
}

void    ft_different_direction(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b)
{
    if (ft_direction(tmp_a->index, a))
    {
        tmp_a->cost = a->size - tmp_a->index;
        ft_rra(a, &tmp_a->cost);
    }
    else
    {
        ft_ra(a, &tmp_a->cost);
    }

    if (ft_direction(tmp_b->index, b))
    {
        tmp_b->cost = b->size - tmp_b->index;
        ft_rrb(b, &tmp_b->cost);
    }
    else 
    {
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
                cost = na->index;
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

void        ft_sort_largee(t_stack *a, t_stack *b)
{
    ft_pb(a, b);
    ft_pb(a, b);
    if (b->top->data < b->top->next->data)
        ft_sbs(b);
     while (a->size > 3)
    {
        t_node *least_cost_node = ft_least_cost(a, b);
        if (least_cost_node)
            printf("Node with least cost in Stack A: %d, Cost: %d and the target is %d\n", least_cost_node->data, least_cost_node->cost, least_cost_node->target->data);
        else
            printf("No node found with least cost in Stack A\n");
        ft_do_the_operations(a,b,least_cost_node , least_cost_node->target );
        ft_pb(a,b);
        
    }
    ft_sort_three(a);
}