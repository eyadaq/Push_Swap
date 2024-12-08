/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 06:56:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 11:42:07 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_checkcase(t_stack *a)
{
	t_node	*min;
	t_node	*max;
	t_node	*node;

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

void	ft_sort_three(t_stack *a)
{
	int	casenum;

	if (ft_checksorted(a))
		return ;
	casenum = ft_checkcase(a);
	if (casenum == 1)
		ft_sas(a);
	else if (casenum == 2)
	{
		ft_sas(a);
		ft_rras(a);
	}
	else if (casenum == 3)
		ft_ras(a);
	else if (casenum == 4)
	{
		ft_sas(a);
		ft_ras(a);
	}
	else if (casenum == 5)
		ft_rras(a);
}

static void	ft_sort_four(t_stack *a, t_stack *b)
{
	t_node	*min;
	t_node	*max;

	ft_pb(a, b);
	ft_sort_three(a);
	min = ft_get_min(a);
	max = ft_get_max(a);
	if (b->top->data < min->data)
		ft_pa(a, b);
	else if (b->top->data > max->data)
	{
		ft_pa(a, b);
		ft_ras(a);
	}
	else
	{
		ft_ras(a);
		ft_pa(a, b);
		if (a->top->data > a->top->next->data)
			ft_sas(a);
		ft_rras(a);
	}
	return ;
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		pos;

	while (a->size > 3)
	{
		node = ft_get_min(a);
		pos = get_position(a, node);
		if (pos <= a->size / 2)
		{
			while (a->top != node)
				ft_ras(a);
		}
		else
		{
			while (a->top != node)
				ft_rras(a);
		}
		ft_pb(a, b);
	}
	ft_sort_three(a);
	while (b->size > 0)
		ft_pa(a, b);
	if (a->top->data > a->top->next->data)
		ft_sas(a);
}

void	ft_sort_small(t_stack *a, t_stack *b)
{
	if (2 == a->size)
	{
		if (!ft_checksorted(a))
			ft_sas(a);
	}
	if (3 == a->size)
		ft_sort_three(a);
	if (4 == a->size)
		ft_sort_four(a, b);
	else
		ft_sort_five(a, b);
	return ;
}
