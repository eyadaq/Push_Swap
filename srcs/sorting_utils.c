/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:59:58 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/02 08:51:05 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node     *ft_get_max(t_stack *stack)
{
    t_node  *node;
    int     max;
    t_node  *maxnode;

    node = stack->top;
    max = stack->top->data;
    maxnode = stack->top;
    while (node->next != NULL)
    {
        node = node->next;
        if (node->data > max)
        {
            max = node->data;
            maxnode = node;           
        }
    }
    return (maxnode);   
}

t_node     *ft_get_min(t_stack *stack)
{
    t_node  *node;
    t_node  *minnode;
    int     min;

    node = stack->top;
    min = stack->top->data;
    minnode = node;
    while (node->next != NULL)
    {
        node = node->next;
        if (node->data < min)
        {
            min = node->data;
            minnode = node;
        }
    }
    return (minnode);
}

int     ft_checksorted(t_stack *stack)
{
    t_node *node;

    if (stack->size == 0)
        return (1);
    node = stack->top;
    while (node->next != NULL)
    {
        if (node->data > node->next->data)
            return (0);
        node = node->next;
    }
    return (1);
}
int     ft_largest_smaller_index(t_stack *s, t_node *node)
{
    t_node *temp;
    int res;
    int first;
    int largest;

    temp = s->top;
    res = -1;
    first = 1;
    largest = INT_MIN;
    while (temp)
    {
        if (first && temp->data < node->data)
        {
            res = temp->index;
            first = 0;
            largest = temp->data;
        }
        if ((temp->data > largest) && (temp->data < node->data))
        {
            res = temp->index;
            largest = temp->data;
        }
        temp = temp->next;
    }
    return (res);
}

void    ft_calc_cost(t_stack *a, t_stack *b)
{
    t_node  *temp_a;
    int         b_index;
        
    temp_a = a->top;
    while (temp_a)
    {
        b_index = ft_calc_bcost(b, temp_a);
        //ft_printf("the node -> %d has b index of -> %d\n",temp_a->data, b_index);
        if (temp_a->index <= (a->size / 2))
            temp_a->cost = ((temp_a->index) + b_index);
        else if (temp_a->index > (a->size / 2))
            temp_a->cost = ((a->size - temp_a->index) + 2 + b_index);
        temp_a = temp_a->next;
    }
}
