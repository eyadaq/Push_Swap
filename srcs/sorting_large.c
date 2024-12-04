/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/04 10:34:28 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Find the largest node smaller than the given node in the stack
t_node *ft_find_target_node(t_stack *stack, t_node *node)
{
    t_node *current = NULL;
    t_node *target_node = NULL;

    if (!stack || !node)
        return NULL;

    current = stack->top;
    while (current)
    {
        // Find the largest node in B that is smaller than the node in A
        if (current->data < node->data)
        {
            if (!target_node || current->data > target_node->data)
            {
                target_node = current;
            }
        }
        current = current->next;
    }

    // If no smaller node found, return the maximum node
    if (!target_node)
        return ft_get_max(stack);

    return target_node;
}

// Calculate cost for moving a node to the correct position
int ft_calculate_node_cost(t_stack *a, t_stack *b, t_node *node)
{
    int a_cost = 0;
    int b_cost = 0;
    t_node *target = NULL;

    // Calculate cost in stack A
    a_cost = node->index;
    if (a_cost > a->size / 2)
        a_cost = a->size - a_cost - 1;

    // Find target node in stack B
    target = ft_find_target_node(b, node);
    
    // Calculate cost in stack B
    b_cost = target->index - 1;
    if (b_cost > b->size / 2)
        b_cost = b->size - b_cost;

    return a_cost + b_cost;
}

// Find the node with the lowest push cost
t_node *ft_find_cheapest_node(t_stack *a, t_stack *b)
{
    t_node *current = a->top;
    t_node *cheapest = NULL;
    int min_cost = INT_MAX;
    int current_cost = 0;

    while (current)
    {
        current_cost = ft_calculate_node_cost(a, b, current);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            cheapest = current;
        }
        current = current->next;
    }

    return cheapest;
}

// Rotate stacks to bring nodes to the top
void ft_rotate_to_top(t_stack *a, t_stack *b, t_node *a_node, t_node *b_target)
{
    int a_pos = a_node->index - 1;
    int b_pos = b_target->index - 1;
    int a_size = a->size;
    int b_size = b->size;

    // Optimize rotation
    while (a_pos > 0 && b_pos > 0)
    {
        ft_rr(a, b);
        a_pos--;
        b_pos--;
    }

    // Rotate A
    while (a->top != a_node)
    {
        if (a_pos <= a_size / 2)
            ft_ra(a);
        else
            ft_rra(a);
    }

    // Rotate B
    while (b->top != b_target)
    {
        if (b_pos <= b_size / 2)
            ft_rb(b);
        else
            ft_rrb(b);
    }
}
// Helper function to align the final stack
void ft_align_stack(t_stack *a)
{
    t_node *min = ft_get_min(a);
    int min_pos = min->index - 1;
    int stack_size = a->size;

    while (a->top != min)
    {
        if (min_pos <= stack_size / 2)
            ft_ra(a);
        else
            ft_rra(a);
    }
}
// Main sorting function for large number of elements
void ft_sort_large(t_stack *a, t_stack *b)
{
    // Move first two elements to B to start
    ft_pb(a, b);
    ft_pb(a, b);

    // Ensure initial order in B
    if (b->top->data < b->top->next->data)
        ft_sb(b);

    // Push elements from A to B with cost optimization
    while (a->size > 3)
    {
        t_node *cheapest = ft_find_cheapest_node(a, b);
        t_node *target = ft_find_target_node(b, cheapest);

        // Rotate and push
        ft_rotate_to_top(a, b, cheapest, target);
        ft_pb(a, b);
    }

    // Sort remaining 3 elements in A
    ft_sort_small(a, b);

    // Move all elements back to A
//    ft_move_b_to_a(a, b);

    // Final alignment
    ft_align_stack(a);
}

