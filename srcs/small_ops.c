/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:10:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/06 23:27:56 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void                ft_sas(t_stack *a)
{
    ft_swap(a);
    ft_get_indexes(a);
    ft_printf("%s\n", "sa");
}
void                ft_rras(t_stack *a)
{
    ft_reverse_rotate(a);
    ft_get_indexes(a);
    ft_printf("%s\n", "rra");
}

void                ft_ras(t_stack *a)
{
    ft_rotate(a);
    ft_get_indexes(a);
    ft_printf("%s\n", "ra");
}

void                ft_sbs(t_stack *b)
{
    ft_swap(b);
    ft_get_indexes(b);
    ft_printf("%s\n", "sb");
}