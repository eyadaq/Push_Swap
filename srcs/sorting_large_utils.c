/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:32:25 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/03 21:46:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int ft_calc_bcost(t_stack *b, t_node *node)
// {
//     int position;
//     int cost;
//     t_node *current;
    
//     position = 0;
//     current = b->top;
//     while (current != NULL)
//     {
//         if (current->data == node->data)
//         {
//             break;
//         }
//         position++;
//         current = current->next;
//     }
//     if (position < b->size / 2)
//         cost = position;
//     else
//         cost = b->size - position;
//     return cost;
// }

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

void        ft_move_a(t_stack *a, t_node *node)
{
    t_node      *n;

    n = a->top;
    while (n->index > (a->size / 2) && (a->top != node))
    {
        ft_rra(a);
    }
    if (a->top == node)
        return ;
    while (n->index < (a->size / 2) && (a->top != node))
    {
        ft_ra(a);
    }
    return ;
}

void        ft_move_b(t_stack *b, t_node *node)
{
    t_node      *n;

    n = b->top;
    while (n->index > (b->size / 2) && (b->top != node))
    {
        ft_rrb(b);
    }
    if (b->top == node)
        return ;
    while (n->index < (b->size / 2) && (b->top != node))
    {
        ft_rb(b);
    }
    return ;
}

void    ft_make_large_top(t_stack *b)
{
    t_node *max;

    max = ft_get_max(b);
    
    if (b->top == max)
        return ;
    ft_move_b(b,max);
    return ;
}

void    ft_sort_large(t_stack *a, t_stack *b)
{
    t_node *leastcost;
    t_node  *target;
    t_node  *max;
    t_node  *min;

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
            target = NULL;
            ft_pb(a,b);
        }
        else if (leastcost->data < min->data)
        {
            target = NULL;
            ft_pb(a,b);
            ft_rb(b);
        }
        else {
            target = ft_find_largest_smaller_node(b, leastcost);
            ft_printf("the node is  %d and the smallest is %d", leastcost->data,target->data);
            ft_move_a(a, leastcost);
            ft_move_b(b, target);
            ft_pb(a,b);
            ft_make_large_top(b);
        }
    }
    ft_print_stack(b);
    ft_sort_small(a,b);
    return ;
}
/*
    1 - Push the first two nodes and sort them in descending order.  --> Done
    2 - Claculate the costs by:
        a - Calculate How much moves you need to make the top of the stack A. --> 💀
        b - Get the index of the larges element that is smaller than the node in A 💀
        c - Calaculate How much it needs to be the top of the stack. 💀
        d - Add the steps A and C together and save the index of the target; 💀
        e - Do it for all of the nodes;💀
    3 - Select the node with the least push cost;💀
    4 - Move it to the top and move the b node to the top;💀
    5 - Push the node and re arrange b.💀
    6 - Do the same until 3 elements in stack A are left.💀
    7 - Sort the last 3 elements in A in ascending order,💀
    8 - ....... To be continued.💀
*/