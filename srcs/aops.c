/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:10:00 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/02 08:38:15 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_pa(t_stack *a, t_stack *b)
{
    ft_push(b, a);
    ft_get_indexes(a);
    ft_get_indexes(b);
    ft_printf("%s\n", "pa");
}
void    ft_sa(t_stack *a)
{
    ft_swap(a);
    ft_get_indexes(a);
    ft_printf("%s\n", "sa");
}
void    ft_rra(t_stack *a)
{
    ft_reverse_rotate(a);
    ft_get_indexes(a);
    ft_printf("%s\n", "rra");   
}
void    ft_ra(t_stack *a)
{
    ft_rotate(a);
    ft_get_indexes(a);
    ft_printf("%s\n", "ra");
}