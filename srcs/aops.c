/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:10:00 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/07 21:00:02 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_pa(t_stack *a, t_stack *b)
{
    ft_push(b, a);
    ft_printf("%s\n", "pa");
}
void    ft_sa(t_stack *a, int *count)
{
    while (*count != 0)
    {
        ft_swap(a);
        (*count)--;
        ft_printf("%s\n", "sa");
    }
    return ;
}
void    ft_rra(t_stack *a, int *count)
{
    while (*count != 0)
    {
        ft_reverse_rotate(a);
        (*count)--;
        ft_printf("%s\n", "rra");
    }
    return ;
}
void    ft_ra(t_stack *a, int *count)
{
    while (*count != 0)
    {
        ft_rotate(a);
        (*count)--;
        ft_printf("%s\n", "ra");
    }
    return ;
}

