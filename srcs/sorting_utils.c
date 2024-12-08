/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:59:58 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 11:42:49 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_get_max(t_stack *stack)
{
	t_node	*node;
	int		max;
	t_node	*maxnode;

	node = stack->top;
	max = node->data;
	maxnode = stack->top;
	while (node)
	{
		if (node->data > max)
		{
			max = node->data;
			maxnode = node;
		}
		node = node->next;
	}
	return (maxnode);
}

t_node	*ft_get_min(t_stack *stack)
{
	t_node	*node;
	t_node	*minnode;
	int		min;

	node = stack->top;
	min = node->data;
	minnode = node;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			minnode = node;
		}
		node = node->next;
	}
	return (minnode);
}

int	ft_checksorted(t_stack *stack)
{
	t_node	*node;

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

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size < 6)
		ft_sort_small(a, b);
	else
		ft_sort_large(a, b);
	return ;
}

int	get_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		position;

	current = stack->top;
	position = 0;
	while (current != NULL)
	{
		if (current == node)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
