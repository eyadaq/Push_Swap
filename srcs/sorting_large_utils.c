/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:32:25 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/03 09:13:11 by eaqrabaw         ###   ########.fr       */
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
        ft_printf("the node is %d acost = %d , the bcost = %d and the total is %d\n",node->data ,total_cost, acost, bcost);
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