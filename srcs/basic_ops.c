/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:28:17 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/11/27 07:40:54 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_stack *stack_x, t_stack *stack_y)
{
	t_node	*temp;

	if (stack_x == NULL || stack_y == NULL)
		return ;
	if (stack_x->top == NULL)
		return ;
	temp = stack_x->top;
	stack_x->top = temp->next;
	if (stack_y->top == NULL)
	{
		stack_y->top = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack_y->top;
		stack_y->top = temp;
	}
	stack_x->size--;
	stack_y->size++;
}

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL)
		return ;
	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	ft_rotate(t_stack *stack)
{
	t_node	*first;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	ft_nodeadd_back(stack, first);
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;
	t_node	*temp;

	first = stack->top;
	last = ft_lastnode(first);
	temp = ft_before_lastnode(first);
	if (temp != NULL)
	{
		temp->next = NULL;
		last->next = first;
		stack->top = last;
	}
}
