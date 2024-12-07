/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:58:07 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/07 22:52:48 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr(t_stack *stacka, t_stack *stackb, t_node *tmp_a, t_node *tmp_b)
{
	while (tmp_a->cost != 0 && tmp_b->cost != 0)
    {
  		ft_rotate(stacka);
		ft_rotate(stackb);
        tmp_a->cost--;
        tmp_b->cost--;
		ft_printf("%s\n", "rr");
    }
}

void ft_rrr(t_stack *stacka, t_stack *stackb, t_node *tmp_a, t_node *tmp_b)
{
    while (tmp_a->cost != 0 && tmp_b->cost != 0)
    {   
        ft_reverse_rotate(stacka);
        ft_reverse_rotate(stackb);
        tmp_a->cost--;
        tmp_b->cost--;
        ft_printf("%s\n", "rrr");
    }
}

void	ft_ss(t_stack *stack_x, t_stack *stack_y, t_node *tmp_a, t_node *tmp_b)
{
	while (tmp_a->cost > 0 && tmp_b->cost > 0)
	{
		ft_swap(stack_x);
		ft_swap(stack_y);
		tmp_a->cost--;
        tmp_b->cost--;
		ft_printf("%s\n", "ss");
	}
}