/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:10:00 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/06 23:28:25 by eaqrabaw         ###   ########.fr       */
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
void    ft_sa(t_stack *a, int *count)
{
    while (*count != 0)
    {
        ft_swap(a);
        ft_get_indexes(a);
        (*count)--;
        ft_printf("%s\n", "sa");
    }
}
void    ft_rra(t_stack *a, int *count)
{
    while (*count != 0)
    {
        ft_reverse_rotate(a);
        ft_get_indexes(a);
        (*count)--;
        ft_printf("%s\n", "rra");
    }   
}
void    ft_ra(t_stack *a, int *count)
{
    while (*count != 0)
    {
        ft_rotate(a);
        ft_get_indexes(a);
        (*count)--;
        ft_printf("%s\n", "ra");
    }
}

