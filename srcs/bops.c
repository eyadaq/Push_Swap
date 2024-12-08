/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:10:03 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/08 21:59:27 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_printf("%s\n", "pb");
}

void	ft_sb(t_stack *b, int *count)
{
	while (*count != 0)
	{
		ft_swap(b);
		ft_printf("%s\n", "sb");
		(*count)--;
	}
	return ;
}

void	ft_rrb(t_stack *b, int *count)
{
	while (*count != 0)
	{
		ft_reverse_rotate(b);
		ft_printf("%s\n", "rrb");
		(*count)--;
	}
	return ;
}

void	ft_rb(t_stack *b, int *count)
{
	while (*count != 0)
	{
		ft_rotate(b);
		ft_printf("%s\n", "rb");
		(*count)--;
	}
	return ;
}
