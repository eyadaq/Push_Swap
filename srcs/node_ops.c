/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:54:13 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 11:41:24 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lastnode(t_node *lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			last = lst;
		lst = lst->next;
	}
	return (last);
}

void	ft_nodeadd_back(t_stack *stack, t_node *newnode)
{
	t_node	*start;

	start = stack->top;
	if (start != NULL)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
		newnode->prev = start;
	}
	else
	{
		stack->top = newnode;
		newnode->prev = NULL;
	}
}

void	ft_nodeadd_front(t_stack *stack, t_node *newnode)
{
	newnode->next = stack->top;
	if (stack->top != NULL)
	{
		stack->top->prev = newnode;
	}
	newnode->prev = NULL;
	stack->top = newnode;
}

t_node	*ft_before_lastnode(t_node *lst)
{
	t_node	*before_last;

	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	before_last = lst;
	return (before_last);
}

void	ft_get_indexes(t_stack *stack)
{
	t_node	*current;
	int		index;

	index = 0;
	current = stack->top;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	current = stack->top;
	while (current)
	{
		current->index = ++index;
		current = current->next;
	}
}
