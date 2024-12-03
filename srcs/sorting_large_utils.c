/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:32:25 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/03 11:07:29 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_calc_bcost(t_stack *b, t_node *node)
{
    int position;
    int cost;

    position = 0;
    t_node *current = b->top;

    // Traverse the stack to find the position of the node
    while (current != NULL)
    {
        if (current->data == node->data)
        {
            break;
        }
        position++;
        current = current->next;
    }

    // Calculate the cost
    if (position < b->size / 2)
        cost = position;  // rotate stack b
    else
        cost = b->size - position;  // reverse rotate stack b

    return cost;
}

int ft_calc_acost(t_stack *a, t_node *node)
{
    int position;
    int cost;

    position = 0;
    t_node *current = a->top;

    // Traverse the stack to find the position of the node
    while (current != NULL)
    {
        if (current->data == node->data)
        {
            break;
        }
        position++;
        current = current->next;
    }

    // Calculate the cost
    if (position < a->size / 2)
        cost = position;  // rotate stack a
    else
        cost = a->size - position;  // reverse rotate stack a

    return cost;
}

void ft_calculate_cost(t_stack *a, t_stack *b)
{
    t_node *node = a->top;
    int acost, bcost, total_cost;

    while (node != NULL)
    {
        acost = ft_calc_acost(a, node);  // Calculate cost for stack a
        bcost = ft_calc_bcost(b, node);  // Calculate cost for stack b

        // Calculate the total cost (you can choose to sum or use another logic here)
        total_cost = acost + bcost;
        // Save the cost in the node
        node->cost = total_cost;

        node = node->next;  // Move to the next node
    }
}

t_node      *ft_get_least_cost(t_stack *a)
{
    t_node *node;
    t_node         *least;

    node = a->top;
    least = a->top;

    while (node)
    {
        if (node->cost < least->cost)
            least = node;
        node = node->next;
    }
    return (least);
}

void        ft_move_a(t_stack *a, t_node *node)
{
    t_node      *n;

    n = a->top;
    if (n->index > (a->size / 2) && (a->top != node))
    {
        ft_rra(a);
    }
    else if (n->index < (a->size / 2) && (a->top != node))
    {
        ft_ra(a);
    }
    return ;
}

void        ft_move_b(t_stack *b, t_node *node)
{
    t_node      *n;

    n = b->top;
    if (n->index > (b->size / 2) && (b->top != node))
    {
        ft_rrb(b);
    }
    else if (n->index < (b->size / 2) && (b->top != node))
    {
        ft_rb(b);
    }
    return ;
}

void    ft_make_large_top(t_stack *a)
{
    t_node *max;

    max = ft_get_max(a);
    
    if (a->top == max)
        return ;
    ft_move_a(a,max);
    return ;
}

t_node *ft_find_largest_smaller_node(t_stack *stack, t_node *node)
{
    t_node *current = stack->top;
    t_node *largest_smaller_node = NULL;

    while (current != NULL)
    {
        // Check if the current node's data is smaller than the given node's data
        // and is larger than the previously found "largest smaller node"
        if (current->data < node->data)
        {
            if (largest_smaller_node == NULL || current->data > largest_smaller_node->data)
            {
                largest_smaller_node = current;
            }
        }
        current = current->next;
    }

    return largest_smaller_node;
}

void    ft_sort_large(t_stack *a, t_stack *b)
{
    t_node *leastcost;
    t_node  *target;

    ft_pb(a, b);
    ft_pb(a, b);
    ft_get_indexes(a);
    ft_get_indexes(b);
    ft_calculate_cost(a,b);
    leastcost = ft_get_least_cost(a);
    target = ft_find_largest_smaller_node(b, leastcost);
    if (b->top->data < b->top->next->data)
        ft_sb(b);
    while (a->size != 3)
    {
        ft_move_a(a, leastcost);
        ft_move_b(b, target);
        ft_pb(a,b);
        ft_make_large_top(b);
        ft_get_indexes(a);
        ft_get_indexes(b);
        ft_calculate_cost(a,b);
        leastcost = ft_get_least_cost(a);
        target = ft_find_largest_smaller_node(b, leastcost);
    }
    ft_sort_small(a,b);
    return ;
}
