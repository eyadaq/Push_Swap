/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:10:03 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/01 09:42:48 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_pb(t_stack *a, t_stack *b)
{
    ft_push(a, b);
    ft_get_indexes(a);
    ft_get_indexes(b);
    ft_printf("%s\n", "pb");
    ft_print_stack(b);
}

void    ft_sb(t_stack *b)
{
    ft_swap(b);
    ft_get_indexes(b);
    ft_printf("%s\n", "sb");
}

void    ft_rrb(t_stack *b)
{
    ft_reverse_rotate(b);
    ft_get_indexes(b);
    ft_printf("%s\n", "rrb");
    ft_print_stack(b);
}

void    ft_rb(t_stack *b)
{
    ft_rotate(b);
    ft_get_indexes(b);
    ft_printf("%s\n", "rb");
    ft_print_stack(b);
}