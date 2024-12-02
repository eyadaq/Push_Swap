/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 06:56:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/11/28 23:59:43 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int     ft_checkcase(t_stack *a)
{
    t_node  *min;
    t_node   *max;
    t_node  *node;

    if (a->size != 3)
        return (0);
    node = a->top;
    min = ft_get_min(a);
    max = ft_get_max(a);
    if (node == min)
        return (4);
    if (node == max)
    {
        if (node->next->data > node->next->next->data)
            return (2);
        return (3);
    }
    if (node->next == max)
        return (5);
    return (1);
}
static int     get_position(t_stack *stack, t_node *node)
{
    t_node *current;
    int position;

    current = stack->top;
    position = 0;
    while (current != NULL)
    {
        if (current == node)
            return position;
        current = current->next;
        position++;
    }
    return -1;
}

void    ft_sort_three(t_stack *a)
{
    int        casenum;

    if (ft_checksorted(a))
        return ;
    casenum = ft_checkcase(a);
    if (casenum == 1)
        ft_sa(a);
    else if (casenum == 2)
    {
        ft_sa(a);
        ft_rra(a); 
    }
    else if (casenum == 3)
        ft_ra(a);
    else if (casenum == 4)
    {
        ft_sa(a);
        ft_ra(a);
    }
    else if (casenum == 5)
        ft_rra(a);
    if (ft_checksorted(a))
        return ;
    ft_sort_three(a);
}

static void    ft_sort_four(t_stack *a, t_stack *b)
{
    t_node     *min;
    t_node     *max;
    
    ft_pb(a,b);
    ft_sort_three(a);
    min = ft_get_min(a);
    max = ft_get_max(a);
    if (b->top->data < min->data)
        ft_pa(a,b);
    else if (b->top->data > max->data)
    {
        ft_pa(a,b);
        ft_ra(a);
    }
    else 
    {
        ft_ra(a);
        ft_pa(a, b);
        if (a->top->data > a->top->next->data)
            ft_sa(a);
        ft_rra(a);
    }
    return ;
}

void    ft_sort_five(t_stack *a, t_stack *b)
{
    t_node  *node;
    int     pos;

    while (a->size > 3)
    {
        node = ft_get_min(a);
        pos = get_position(a, node);
        if (pos <= a->size / 2)
        {
            while (a->top != node)
                ft_ra(a);
        }
        else
        {
            while (a->top != node)
                ft_rra(a);
        }
        ft_pb(a, b);
    }
    ft_sort_three(a);
    while (b->size > 0)
        ft_pa(a, b);
    if (a->top->data > a->top->next->data)
        ft_sa(a);
}

void    ft_sortsmall(t_stack *a, t_stack *b)
{    
    if (2 == a->size)
    {
        if (!ft_checksorted(a))
            ft_sa(a);
    }
    if (3 == a->size)
        ft_sort_three(a);
    if (4 == a->size)
        ft_sort_four(a, b);
    else 
        ft_sort_five(a, b);
    return ;
}
