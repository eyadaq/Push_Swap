/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:58:07 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/11/27 07:40:50 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr(t_stack *stacka, t_stack *stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
	ft_printf("%s\n", "rr");
}

void	ft_rrr(t_stack *stacka, t_stack *stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
	ft_printf("%s\n", "rrr");
}

void	ft_ss(t_stack *stack_x, t_stack *stack_y)
{
	ft_swap(stack_x);
	ft_swap(stack_y);
	ft_printf("%s\n", "ss");
}