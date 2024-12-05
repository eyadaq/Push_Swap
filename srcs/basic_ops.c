/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:28:17 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/05 09:24:14 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_push(t_stack *stack_x, t_stack *stack_y)
{
    t_node *temp;

    if (stack_x == NULL || stack_y == NULL)
        return;
    if (stack_x->top == NULL)
        return;
    temp = stack_x->top;
    stack_x->top = temp->next;
    if (stack_x->top != NULL)
        stack_x->top->prev = NULL;
    if (stack_y->top == NULL)
    {
        stack_y->top = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp->next = stack_y->top;
        stack_y->top->prev = temp;
        stack_y->top = temp;
        temp->prev = NULL;
    }
    stack_x->size--;
    stack_y->size++;
}

void ft_swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (stack == NULL)
        return;
    if (stack->top == NULL)
        return;
    if (stack->top->next == NULL)
        return;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    stack->top = second;
}

void ft_rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = stack->top;
    stack->top = first->next;
    stack->top->prev = NULL;
    first->next = NULL;
    last = stack->top;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->prev = last;
}

void ft_reverse_rotate(t_stack *stack)
{
    t_node *last;
    t_node *first;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = stack->top;
    last = stack->top;
    while (last->next != NULL)
        last = last->next;
    if (last->prev != NULL)
        last->prev->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    stack->top = last;
}
