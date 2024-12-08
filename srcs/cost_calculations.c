/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:11:55 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 11:40:05 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_least_cost(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*least;

	ft_get_indexes(a);
	ft_get_indexes(b);
	ft_calculate_costs(a, b);
	node = a->top;
	least = node;
	while (node)
	{
		if (node->cost < least->cost)
			least = node;
		node = node->next;
	}
	return (least);
}

void	ft_calculate_costs(t_stack *a, t_stack *b)
{
	t_node	*sa;

	sa = a->top;
	while (sa)
	{
		sa->target = ft_find_target(b, sa);
		sa->cost = ft_cost(a, b, sa, sa->target);
		sa = sa->next;
	}
	return ;
}

int	ft_cost_same_direction(t_stack *a, t_stack *b, t_node *na, t_node *nb)
{
	int	cost;

	if (ft_direction(na->index, a))
	{
		if ((a->size - na->index) > (b->size - nb->index))
			cost = a->size - na->index;
		else
			cost = b->size - nb->index;
	}
	else
	{
		if (na->index > nb->index)
			cost = na->index - 1;
		else
			cost = nb->index;
	}
	return (cost);
}

int	ft_cost(t_stack *a, t_stack *b, t_node *na, t_node *nb)
{
	int	cost;

	cost = 0;
	if (ft_direction(na->index, a) == ft_direction(nb->index, b))
	{
		return (ft_cost_same_direction(a, b, na, nb));
	}
	if (ft_direction(na->index, a))
		cost = a->size - na->index;
	else
		cost = na->index;
	if (ft_direction(nb->index, b))
		cost += b->size - nb->index;
	else
		cost += nb->index;
	return (cost);
}

t_node	*ft_find_target(t_stack *stack, t_node *node)
{
	t_node	*target;
	t_node	*current;

	if (!stack || !node || !stack->top)
		return (NULL);
	current = stack->top;
	target = NULL;
	while (current)
	{
		if (current->data < node->data)
		{
			if (!target || current->data > target->data)
			{
				target = current;
			}
		}
		current = current->next;
	}
	if (!target)
		target = ft_get_max(stack);
	return (target);
}
