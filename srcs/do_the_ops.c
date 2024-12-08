/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:15:32 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 07:16:37 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_direction(int tmp, t_stack *stack_a)
{
	if (tmp > (stack_a->size / 2))
		return (1);
	else
		return (0);
}

void	ft_same_direction(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b)
{
	if (ft_direction(tmp_a->index, a))
	{
		tmp_a->cost = a->size - tmp_a->index + 1;
		tmp_b->cost = b->size - tmp_b->index + 1;
		ft_rrr(a, b, tmp_a, tmp_b);
		ft_rra(a, &tmp_a->cost);
		ft_rrb(b, &tmp_b->cost);
	}
	else
	{
		tmp_a->cost = tmp_a->index - 1;
		tmp_b->cost = tmp_b->index - 1;
		ft_rr(a, b, tmp_a, tmp_b);
		if (tmp_a->index != 1)
			ft_ra(a, &tmp_a->cost);
		if (tmp_b->index != 1)
			ft_rb(b, &tmp_b->cost);
	}
}

void	ft_different_direction(t_stack *a, t_stack *b, t_node *tmp_a,
		t_node *tmp_b)
{
	if (ft_direction(tmp_a->index, a))
	{
		tmp_a->cost = (1 + a->size - tmp_a->index);
		ft_rra(a, &tmp_a->cost);
	}
	else
	{
		tmp_a->cost = (tmp_a->index - 1);
		ft_ra(a, &tmp_a->cost);
	}
	if (ft_direction(tmp_b->index, b))
	{
		tmp_b->cost = 1 + b->size - tmp_b->index;
		ft_rrb(b, &tmp_b->cost);
	}
	else
	{
		tmp_b->cost = tmp_b->index - 1;
		if (tmp_b->index != 1)
			ft_rb(b, &tmp_b->cost);
	}
}

void	ft_do_the_operations(t_stack *a, t_stack *b, t_node *tmp_a,
		t_node *tmp_b)
{
	int	index_a;
	int	index_b;

	index_a = tmp_a->index;
	index_b = tmp_b->index;
	if (ft_direction(index_a, a) == ft_direction(index_b, b))
	{
		ft_same_direction(a, b, tmp_a, tmp_b);
	}
	else
	{
		ft_different_direction(a, b, tmp_a, tmp_b);
	}
}
