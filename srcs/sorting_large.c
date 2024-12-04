/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:09:01 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/04 09:31:46 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int ft_calc_acost(t_stack *a, t_node *node)
{
    int position;
    int cost;

    position = 0;
    t_node *current = a->top;

    while (current != NULL)
    {
        if (current->data == node->data)
        {
            break;
        }
        position++;
        current = current->next;
    }
    if (position < a->size / 2)
        cost = position;
    else
        cost = a->size - position;
    return cost;
}

void ft_calculate_cost(t_stack *a, t_stack *b)
{
    t_node *node = a->top;
    t_node *largest_smaller;
    int acost, bcost, total_cost;
    
    while (node != NULL)
    {
        acost = ft_calc_acost(a, node);  // Calculate cost for stack a
        largest_smaller = ft_find_largest_smaller_node(b, node);
        if (!largest_smaller)
        {
            bcost = 0;
        }
        else {
            bcost = largest_smaller->index;
        }
        //ft_calc_bcost(b, largest_smaller);  // Calculate cost for stack b

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

void ft_make_top_b(t_stack *stack, t_node *node)
{
    int position = 0;
    t_node *current = stack->top;

    // Find the position of the node in the stack
    while (current != NULL && current != node)
    {
        current = current->next;
        position++;
    }

    // If the node is not found, return
    if (current == NULL)
        return;

    // Determine whether to rotate or reverse rotate
    if (position <= stack->size / 2)
    {
        // Rotate until the node is at the top
        while (stack->top != node)
        {
            ft_rb(stack);
        }
    }
    else
    {
        // Reverse rotate until the node is at the top
        while (stack->top != node)
        {
            ft_rrb(stack);
        }
    }
}

void    ft_make_large_top(t_stack *b)
{
    t_node *max;

    max = ft_get_max(b);
    
    if (b->top == max)
        return ;
    ft_make_top_b(b,max);
    return ;
}

t_node *ft_find_insert_position(t_stack *a, t_node *node)
{
    t_node *current = a->top;
    t_node *insert_position = a->top;

    while (current != NULL)
    {
        if (current->data > node->data)
        {
            insert_position = current;
            break;
        }
        current = current->next;
    }
    return insert_position;
}

void ft_optimize_rotation(t_stack *a, t_stack *b, int a_pos, int b_pos)
{
    // Simultaneously rotate both stacks if possible
    while (a_pos > 0 && b_pos > 0)
    {
        ft_rr(a, b);
        a_pos--;
        b_pos--;
    }

    // Rotate stack A if needed
    while (a_pos > 0)
    {
        ft_ra(a);
        a_pos--;
    }

    // Rotate stack B if needed
    while (b_pos > 0)
    {
        ft_rb(b);
        b_pos--;
    }
}

void ft_optimize_reverse_rotation(t_stack *a, t_stack *b, int a_pos, int b_pos)
{
    int a_size = a->size;
    int b_size = b->size;

    // Simultaneously reverse rotate both stacks if possible
    while (a_pos < a_size && b_pos < b_size)
    {
        ft_rrr(a, b);
        a_pos++;
        b_pos++;
    }

    // Reverse rotate stack A if needed
    while (a_pos < a_size)
    {
        ft_rra(a);
        a_pos++;
    }

    // Reverse rotate stack B if needed
    while (b_pos < b_size)
    {
        ft_rrb(b);
        b_pos++;
    }
}

void ft_make_top_a(t_stack *a, t_stack *b, t_node *a_node, t_node *b_target)
{
    int a_pos = 0;
    int b_pos = 0;
    t_node *current;


    current = a->top;
    while (current != NULL && current != a_node)
    {
        current = current->next;
        a_pos++;
    }
    current = b->top;
    while (current != NULL && current != b_target)
    {
        current = current->next;
        b_pos++;
    }
    if (a_pos <= a->size / 2 && b_pos <= b->size / 2)
    {
        ft_optimize_rotation(a, b, a_pos, b_pos);
    }
    else if (a_pos > a->size / 2 && b_pos > b->size / 2)
    {
        a_pos = a->size - a_pos;
        b_pos = b->size - b_pos;
        ft_optimize_reverse_rotation(a, b, a_pos, b_pos);
    }
    else
    {
        if (a_pos <= a->size / 2)
        {
            while (a->top != a_node)
                ft_ra(a);
        }
        else
        {
            a_pos = a->size - a_pos;
            while (a->top != a_node)
                ft_rra(a);
        }

        if (b_pos <= b->size / 2)
        {
            while (b->top != b_target)
                ft_rb(b);
        }
        else
        {
            b_pos = b->size - b_pos;
            while (b->top != b_target)
                ft_rrb(b);
        }
    }
}

void ft_sort_large(t_stack *a, t_stack *b)
{
    t_node *leastcost;
    t_node *target;
    t_node *max;
    t_node *min;

    ft_pb(a, b);
    ft_pb(a, b);
    if (b->top->data < b->top->next->data)
        ft_sb(b);
    while (a->size != 3)
    {
        ft_get_indexes(a);
        ft_get_indexes(b);
        ft_calculate_cost(a,b);
        max = ft_get_max(b);
        min = ft_get_min(b);
        leastcost = ft_get_least_cost(a);
        
        if (leastcost->data > max->data)
        {
            target = b->top;
            ft_make_top_a(a, b, leastcost, target);
            ft_pb(a,b);
        }
        else if (leastcost->data < min->data)
        {
            target = b->top;
            ft_make_top_a(a, b, leastcost, target);
            ft_pb(a,b);
            ft_rb(b);
        }
        else if (leastcost->data > min->data && leastcost->data < max->data) 
        {
            target = ft_find_largest_smaller_node(b, leastcost);
            ft_make_top_a(a, b, leastcost, target);
            ft_pb(a,b);
        }
    }
    max = ft_get_max(b);
    ft_make_top_b(b, max);
    ft_sort_small(a,b);
    return ;
}